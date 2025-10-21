import os
import time
import numpy as np
from PIL import Image
from multiprocessing import Pool, cpu_count
from scipy.spatial import KDTree
import resource

# Parametry
base_dir = "big_data"
src_img_path = os.path.join(base_dir, "konfident.png")
tiles_dir = os.path.join(base_dir, "zdjecia")
output_dir = os.path.join(base_dir, "out")
os.makedirs(output_dir, exist_ok=True)

tile_size = 100
output_width = 20000
output_height = 20000

# Znajdź unikalną nazwę pliku wynikowego
counter = 1
while True:
    output_path = os.path.join(output_dir, f"result{counter}.png")
    if not os.path.exists(output_path):
        break
    counter += 1

# Globalne zmienne do multiprocessing
global_tiles_np = []
global_kdtree = None

def average_color_np(np_img):
    return tuple(np_img.reshape(-1, 3).mean(axis=0).astype(int))

def load_tile_images(tile_dir, tile_size):
    start = time.time()
    tiles = []
    for root, _, files in os.walk(tile_dir):
        for file in files:
            if file.lower().endswith((".jpg", ".png")):
                file_path = os.path.join(root, file)
                try:
                    img = Image.open(file_path).resize((tile_size, tile_size)).convert("RGB")
                    np_img = np.array(img)
                    tiles.append((average_color_np(np_img), np_img))
                except Exception as e:
                    print(f"Błąd podczas ładowania obrazu {file_path}: {e}")
    print(f"[TIMER] Ładowanie miniatur: {time.time() - start:.2f} s")
    return tiles

def init_worker(tiles_data):
    global global_tiles_np, global_kdtree
    global_tiles_np = tiles_data
    global_kdtree = KDTree([color for color, _ in global_tiles_np])

def closest_tile_np(avg_color):
    _, idx = global_kdtree.query(avg_color)
    return global_tiles_np[idx][1]

def process_column(args):
    x, col_blocks = args
    results = []
    for y, block in col_blocks:
        np_block = np.array(block)
        avg_color = average_color_np(np_block)
        best_tile = closest_tile_np(avg_color)

        # Dopasuj kafelek jeśli jesteśmy przy krawędzi
        block_w, block_h = block.size
        tile_h, tile_w, _ = best_tile.shape
        if block_w != tile_size or block_h != tile_size:
            best_tile = Image.fromarray(best_tile).crop((0, 0, block_w, block_h))
            best_tile = np.array(best_tile)

        results.append((x, y, best_tile))
    return results

def create_mosaic(src_img_path, output_path, tile_size, out_width, out_height, tiles_dir):
    total_start = time.time()

    t = time.time()
    source = Image.open(src_img_path).resize((out_width, out_height)).convert("RGB")
    print(f"[TIMER] Wczytywanie i skalowanie źródła: {time.time() - t:.2f} s")

    tiles = load_tile_images(tiles_dir, tile_size)
    if not tiles:
        print("Brak miniatur w folderze:", tiles_dir)
        return

    t = time.time()
    kd_tree = KDTree([color for color, _ in tiles])
    print(f"[TIMER] Tworzenie KDTree: {time.time() - t:.2f} s")

    mosaic_np = np.zeros((out_height, out_width, 3), dtype=np.uint8)
    args_list = []

    t = time.time()
    for i in range(0, out_width, tile_size):
        col_blocks = []
        for j in range(0, out_height, tile_size):
            block_w = min(tile_size, out_width - i)
            block_h = min(tile_size, out_height - j)
            block = source.crop((i, j, i + block_w, j + block_h))
            col_blocks.append((j, block))
        args_list.append((i, col_blocks))
    print(f"[TIMER] Przygotowanie bloków: {time.time() - t:.2f} s")

    t = time.time()
    with Pool(cpu_count() - 1, initializer=init_worker, initargs=(tiles,)) as pool:
        for result_col in pool.imap_unordered(process_column, args_list, chunksize=10):
            for x, y, tile_np in result_col:
                h, w, _ = tile_np.shape
                mosaic_np[y:y + h, x:x + w] = tile_np
    print(f"[TIMER] Przetwarzanie równoległe: {time.time() - t:.2f} s")

    t = time.time()
    mosaic = Image.fromarray(mosaic_np)
    mosaic.save(output_path)
    print(f"[TIMER] Zapis obrazu: {time.time() - t:.2f} s")

    print("Mozaika zapisana:", output_path)
    print(f"[TIMER] Całkowity czas: {time.time() - total_start:.2f} s")

if __name__ == '__main__':
    resource.setrlimit(resource.RLIMIT_AS, (12 * 1024 ** 3, 12 * 1024 ** 3))
    create_mosaic(src_img_path, output_path, tile_size, output_width, output_height, tiles_dir)
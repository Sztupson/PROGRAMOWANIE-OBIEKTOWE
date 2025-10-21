import os
import time
from PIL import Image
from multiprocessing import Pool, cpu_count
from scipy.spatial import KDTree
import numpy as np

# Parametry
base_dir = "big_data"
src_img_path = os.path.join(base_dir, "aston.png")
tiles_dir = os.path.join(base_dir, "zdjecia")  # folder z kafelkami
output_dir = os.path.join(base_dir, "out")
os.makedirs(output_dir, exist_ok=True)


tile_size = 30
output_width = 10000
output_height = 10000


# Znajdź unikalną nazwę pliku wynikowego
counter = 1
while True:
    output_path = os.path.join(output_dir, f"result{counter}.png")
    if not os.path.exists(output_path):
        break
    counter += 1



# Globalne zmienne do multiprocessing
global_tiles = []
global_kdtree = None

def average_color(image):
    pixels = list(image.getdata())
    n = len(pixels)
    r = sum(p[0] for p in pixels) // n
    g = sum(p[1] for p in pixels) // n
    b = sum(p[2] for p in pixels) // n
    return (r, g, b)

def load_tile_images(tile_dir, tile_size):
    tiles = []
    for root, _, files in os.walk(tile_dir):
        for file in files:
            if file.lower().endswith((".jpg", ".png")):
                file_path = os.path.join(root, file)
                try:
                    img = Image.open(file_path).resize((tile_size, tile_size)).convert("RGB")
                    tiles.append((average_color(img), img))
                except Exception as e:
                    print(f"Błąd podczas ładowania obrazu {file_path}: {e}")
    return tiles

def init_worker(tiles_data):
    global global_tiles, global_kdtree
    global_tiles = tiles_data
    global_kdtree = KDTree([color for color, _ in global_tiles])

def closest_tile_color(avg_color):
    _, idx = global_kdtree.query(avg_color)
    return global_tiles[idx][1]

def process_tile(args):
    x, y, block = args
    avg_color = average_color(block)
    best_tile = closest_tile_color(avg_color)
    return x, y, best_tile

def create_mosaic(src_img_path, output_path, tile_size, out_width, out_height, tiles_dir):
    source = Image.open(src_img_path).resize((out_width, out_height)).convert("RGB")
    tiles = load_tile_images(tiles_dir, tile_size)

    if not tiles:
        print("Brak miniatur w folderze:", tiles_dir)
        return

    mosaic = Image.new('RGB', (out_width, out_height))
    args_list = []

    for i in range(0, out_width, tile_size):
        for j in range(0, out_height, tile_size):
            block = source.crop((i, j, i + tile_size, j + tile_size))
            args_list.append((i, j, block))

    with Pool(cpu_count(), initializer=init_worker, initargs=(tiles,)) as pool:
        results = pool.map(process_tile, args_list, chunksize=100)

    for x, y, tile in results:
        mosaic.paste(tile, (x, y))

    mosaic.save(output_path)
    print("Mozaika zapisana:", output_path)

if __name__ == '__main__':
    start = time.time()
    create_mosaic(src_img_path, output_path, tile_size, output_width, output_height, tiles_dir)
    end = time.time()
    print(f"Zrobione w {end - start:.2f} s")

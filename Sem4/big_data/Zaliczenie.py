import os
import time
from PIL import Image
from multiprocessing import Pool, cpu_count
import resource


src_img_path = "big_data/gory.jpg"
tiles_dir = "big_data/zdjecia"  
output_path = "big_data/out/result5.jpg"

tile_size = 20
output_width = 2200 
output_height = 1414




def average_color(image):
    pixels = list(image.getdata())
    r = sum(p[0] for p in pixels) // len(pixels)
    g = sum(p[1] for p in pixels) // len(pixels)
    b = sum(p[2] for p in pixels) // len(pixels)
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
                    continue
    return tiles




def closest_tile_color(avg_color, tiles):
    def distance(c1, c2):
        return sum((a - b) ** 2 for a, b in zip(c1, c2))
    def tile_distance(tile):
        return distance(avg_color, tile[0])
    return min(tiles, key=tile_distance)[1]




def process_tile(args):
    x, y, block, tiles = args
    avg_color = average_color(block)
    best_tile = closest_tile_color(avg_color, tiles)
    return x, y, best_tile





def create_mosaic(src_img_path, output_path, tile_size, out_width, out_height, tiles_dir):
    source = Image.open(src_img_path).resize((out_width, out_height)).convert("RGB")

    tiles = load_tile_images(tiles_dir, tile_size)
    if not tiles:
        print("Brak miniatur w glownym folderze.")
        return

    mosaic = Image.new('RGB', (out_width, out_height))
    args_list = []

    for i in range(0, out_width, tile_size):
        for j in range(0, out_height, tile_size):
            block = source.crop((i, j, i + tile_size, j + tile_size))
            args_list.append((i, j, block, tiles))

    with Pool(cpu_count() - 2) as pool:
        results = pool.map(process_tile, args_list)

    for x, y, tile in results:
        mosaic.paste(tile, (x, y))

    mosaic.save(output_path)
    print("Mozaika zapisana:", output_path)







if __name__ == '__main__':
    resource.setrlimit(resource.RLIMIT_AS, (12 * 1024 ** 3, 12 * 1024 ** 3))

    start = time.time()
    create_mosaic(src_img_path, output_path, tile_size, output_width, output_height, tiles_dir)
    end = time.time()

    print(f"Wykonano w {end - start:.2f} s")

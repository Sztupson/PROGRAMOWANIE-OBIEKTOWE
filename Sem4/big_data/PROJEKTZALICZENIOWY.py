import os
import time
from PIL import Image
from multiprocessing import Pool, cpu_count

base_dir = ""
source_image_path = os.path.join(base_dir, "trulimero_trulicina.png")  # Twoje główne zdjęcie
tiles_dir = os.path.join(base_dir, "zdjecia2")  # Folder ze zdjęciami, teraz może zawierać podfoldery
output_dir = os.path.join(base_dir, "out2")  # Folder, gdzie będą zapisywane wyniki

tile_size = 20
output_width = 10000
output_height = 16000


def average_color(image):
    pixels = list(image.getdata())
    n = len(pixels)
    r = sum(p[0] for p in pixels) // n
    g = sum(p[1] for p in pixels) // n
    b = sum(p[2] for p in pixels) // n
    return (r, g, b)


def load_tile_images(tile_dir, tile_size):
    tiles = []
    # Używamy os.walk, by przejść przez wszystkie podfoldery
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
    return min(tiles, key=lambda tile: distance(avg_color, tile[0]))[1]


def process_tile(args):
    x, y, block, tile_size, tiles = args
    avg_color = average_color(block)
    best_tile = closest_tile_color(avg_color, tiles)
    return x, y, best_tile


def create_mosaic(source_image_path, output_dir, tile_size, out_width, out_height, tiles_dir):

    source = Image.open(source_image_path).resize((out_width, out_height)).convert("RGB")


    tiles = load_tile_images(tiles_dir, tile_size)
    if not tiles:
        print("Brak miniatur w folderze:", tiles_dir)
        return

    mosaic = Image.new('RGB', (out_width, out_height))
    args_list = []

    for i in range(0, out_width, tile_size):
        for j in range(0, out_height, tile_size):
            block = source.crop((i, j, i + tile_size, j + tile_size))
            args_list.append((i, j, block, tile_size, tiles))


    with Pool(cpu_count()) as pool:
        results = pool.map(process_tile, args_list)


    for x, y, tile in results:
        mosaic.paste(tile, (x, y))


    # Generowanie unikalnej nazwy pliku
    os.makedirs(output_dir, exist_ok=True)
    output_file = get_unique_filename(output_dir, "result.png")

    mosaic.save(output_file)
    print(f"Mozaika zapisana jako: {output_file}")


def get_unique_filename(output_dir, base_filename):
    """
    Funkcja generuje unikalną nazwę pliku w folderze output_dir.
    Jeśli plik o danej nazwie już istnieje, dodaje numer (result1.png, result2.png, etc.)
    """
    counter = 1
    filename, extension = os.path.splitext(base_filename)
    new_filename = base_filename
    
    while os.path.exists(os.path.join(output_dir, new_filename)):
        new_filename = f"{filename}{counter}{extension}"
        counter += 1
    
    return os.path.join(output_dir, new_filename)


if __name__ == '__main__':
    start = time.time()

    

    create_mosaic(source_image_path, output_dir, tile_size, output_width, output_height, tiles_dir)

    end = time.time()
    print(f"Zrobione w {end - start:.2f} s")

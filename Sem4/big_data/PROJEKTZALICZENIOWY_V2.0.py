import os
import time
from PIL import Image
from multiprocessing import Pool, cpu_count
import matplotlib.pyplot as plt  # nowy import

base_dir = ""
source_image_path = os.path.join(base_dir, "trippi_troppi_troppa_trippa.png")
tiles_dir = os.path.join(base_dir, "zdjecia2")
output_dir = os.path.join(base_dir, "out2")

tile_size = 20
output_width = 4000
output_height = 4000


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


def closest_tile_color(avg_color, tiles):
    def distance(c1, c2):
        return sum((a - b) ** 2 for a, b in zip(c1, c2))
    return min(tiles, key=lambda tile: distance(avg_color, tile[0]))[1]


def process_row(args):
    j, row_blocks, tile_size, tiles = args
    row_result = []
    for i, block in row_blocks:
        avg_color = average_color(block)
        best_tile = closest_tile_color(avg_color, tiles)
        row_result.append((i, j, best_tile))
    return row_result


def create_mosaic(source_image_path, output_dir, tile_size, out_width, out_height, tiles_dir):
    source = Image.open(source_image_path).resize((out_width, out_height)).convert("RGB")
    tiles = load_tile_images(tiles_dir, tile_size)
    if not tiles:
        print("Brak miniatur w folderze:", tiles_dir)
        return

    mosaic = Image.new('RGB', (out_width, out_height))

    # Przygotowanie danych do przetwarzania per wiersz
    rows_args = []
    for j in range(0, out_height, tile_size):
        row_blocks = []
        for i in range(0, out_width, tile_size):
            block = source.crop((i, j, i + tile_size, j + tile_size))
            row_blocks.append((i, block))
        rows_args.append((j, row_blocks, tile_size, tiles))

    # Inicjalizacja podglądu
    plt.ion()
    fig, ax = plt.subplots()
    img_show = ax.imshow(mosaic)
    plt.title("Generowanie mozaiki...")
    plt.axis("off")

    with Pool(cpu_count()) as pool:
        for row_result in pool.imap(process_row, rows_args):
            for i, j, tile in row_result:
                mosaic.paste(tile, (i, j))

            # Aktualizacja podglądu po każdym wierszu
            img_show.set_data(mosaic)
            plt.draw()
            plt.pause(0.01)

    plt.ioff()

    os.makedirs(output_dir, exist_ok=True)
    output_file = get_unique_filename(output_dir, "result.png")
    mosaic.save(output_file)
    print(f"Mozaika zapisana jako: {output_file}")


def get_unique_filename(output_dir, base_filename):
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

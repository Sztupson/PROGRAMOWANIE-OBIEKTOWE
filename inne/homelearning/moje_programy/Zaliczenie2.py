import os
import time
from PIL import Image
from multiprocessing import Pool, cpu_count
from scipy.spatial import KDTree

base_dir = "big_data"
src_img_path = os.path.join(base_dir, "aston.png")
tiles_dir = os.path.join(base_dir, "zdjecia")  # folder z kafelkami
output_path = os.path.join(base_dir, "out", "result.png")

tile_size = 50
output_width = 1000*20
output_height = 1000*20



# Optymalizacja: Zmniejszenie liczby próbek pikseli w celu przyspieszenia obliczeń
def average_color(image):
    pixels = list(image.getdata())
    n = len(pixels)
    
    # Weźmy próbkę pikseli, np. co dziesiąty
    sample_size = max(1, n // 100)  # Liczba próbek
    pixels = pixels[::sample_size]  # Co ile pikseli pobierać próbki

    r = sum(p[0] for p in pixels) // len(pixels)
    g = sum(p[1] for p in pixels) // len(pixels)
    b = sum(p[2] for p in pixels) // len(pixels)
    return (r, g, b)

# Funkcja ładowania kafelków z folderu
def load_tile_image_worker(file_path, tile_size):
    try:
        img = Image.open(file_path).resize((tile_size, tile_size)).convert("RGB")
        avg_color = average_color(img)
        return avg_color, img
    except Exception as e:
        print(f"Błąd podczas ładowania obrazu {file_path}: {e}")
        return None

# Optymalizacja: Ładowanie wszystkich kafelków równolegle
def load_tile_images(tile_dir, tile_size):
    files = []
    for root, _, filenames in os.walk(tile_dir):
        for filename in filenames:
            if filename.lower().endswith(('.jpg', '.png')):
                files.append(os.path.join(root, filename))
    
    with Pool(cpu_count()) as pool:
        tiles = pool.starmap(load_tile_image_worker, [(f, tile_size) for f in files])

    # Filtrujemy None (błędy podczas ładowania)
    tiles = [tile for tile in tiles if tile is not None]
    
    # Budujemy KDTree
    colors = [tile[0] for tile in tiles]
    color_tree = KDTree(colors)  # Tworzymy KDTree dla kolorów
    return tiles, color_tree

# Funkcja obliczania odległości RGB
def closest_tile_color(avg_color, tiles, color_tree):
    dist, idx = color_tree.query(avg_color)  # Wyszukaj najbliższy kolor w KDTree
    return tiles[idx][1]  # Zwróć obrazek, który odpowiada temu kolorowi

# Funkcja przetwarzania jednego bloku w mozaice
def process_tile(args):
    x, y, block, tile_size, tiles, color_tree = args
    avg_color = average_color(block)
    best_tile = closest_tile_color(avg_color, tiles, color_tree)
    return x, y, best_tile

# Funkcja tworzenia mozaiki
def create_mosaic(src_img_path, output_path, tile_size, out_width, out_height, tiles_dir):
    source = Image.open(src_img_path).resize((out_width, out_height)).convert("RGB")

    tiles, color_tree = load_tile_images(tiles_dir, tile_size)
    if not tiles:
        print("Brak miniatur w folderze:", tiles_dir)
        return

    mosaic = Image.new('RGB', (out_width, out_height))
    args_list = []

    # Przygotowanie danych wejściowych dla procesów
    for i in range(0, out_width, tile_size):
        for j in range(0, out_height, tile_size):
            block = source.crop((i, j, i + tile_size, j + tile_size))
            args_list.append((i, j, block, tile_size, tiles, color_tree))


    num_workers = int(cpu_count() // 1.5)
    with Pool(num_workers) as pool:
        results = pool.map(process_tile, args_list)

    # Złożenie mozaiki z wyników
    for x, y, tile in results:
        mosaic.paste(tile, (x, y))

    # Zapisanie mozaiki do pliku
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    mosaic.save(output_path, "png", quality=95)
    print("Mozaika zapisana:", output_path)

if __name__ == '__main__':
    start = time.time()

    files = os.listdir(base_dir)
    for f in files:
        if f.lower().endswith(('.jpg', '.png')):
            src_img_path = os.path.join(base_dir, f)
            break

    create_mosaic(src_img_path, output_path, tile_size, output_width, output_height, tiles_dir)

    end = time.time()
    print(f"Zrobione w {end - start:.2f} s")

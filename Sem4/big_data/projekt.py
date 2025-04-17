import os
from PIL import Image
import threading
import time
# Załadowanie pojedyńczego zdjęcia, (w razie png koncertowanie na RGB), resize i zwrócenie załadowanego przez load zdjecia
def load_photo(file_name: str, width: int = 0, height: int = 0):
    photo = Image.open(file_name)
    photo = photo.convert("RGB")
    if width == 0 and height == 0:
        size = photo.size
        photo = photo.resize((size[0], size[1]))
    else:
        photo = photo.resize((width, height))
    return photo

def decrease_pixels(step_block: int, file_name: str, width: int = 0, height: int = 0):
    photo = load_photo(file_name, width, height)

    pixels = photo.load()
    for i in range(int(width / step_block)):
        for j in range(int(height / step_block)):
            r, g, b = (0,0,0)
            for x in range(int(step_block)):
                for y in range(int(step_block)):
                    rPx, gPx, bPx = pixels[i*step_block + x, j*step_block + y]
                    r += rPx
                    g += gPx
                    b += bPx

            r, g, b = int(r/(step_block*step_block)), int(g/(step_block*step_block)), int(b/(step_block*step_block))
            for x in range(step_block):
                for y in range(step_block):
                    pixels[i*step_block + x, j*step_block + y] = r, g, b
    return photo

def save_photo(file_name, photo):
    photo.save(file_name)
def make_small_photo(file_name, step_block):
    photo_small = Image.open(file_name)
    photo_small = photo_small.resize((step_block, step_block))
    photo_small = photo_small.convert("RGB")
    return photo_small

def fill_og_with_small(file_name_og: str,file_out: str,step_block: int, width: int, height: int, floryda: str):
    photo_small = make_small_photo(floryda, step_block)
    # save_photo("trala lakrokodilo.jpg", photo_small)
    photo = load_photo(file_name_og, width, height)
    pixels = photo.load()
    pixelsResult = photo.load()
    for i in range(int(width / step_block)):
        for j in range(int(height / step_block)):
            r, g, b = (0,0,0)
            for x in range(step_block):
                for y in range(step_block):
                    rPpx, gPpx, bPpx = pixels[i*step_block+x, j*step_block+y]
                    r += rPpx
                    g +=gPpx
                    b += bPpx
            rgb_part = (int(r/(step_block*step_block)), int(g/(step_block*step_block)), int(b/(step_block*step_block)))

            photo_part = Image.new('RGB', (step_block, step_block), rgb_part)
            photo_blended = Image.blend(photo_part, photo_small, alpha=0.5)
            pixels_blended = photo_blended.load()
            for x in range(step_block):
                for y in range(step_block):
                    pixelsResult[i * step_block + x, j * step_block + y] = pixels_blended[x, y]
    save_photo(file_out, photo)

def fill_all_photos(dir_out):
    path_with_photos = os.path.join(os.getcwd(), "zdjecia")
    files = os.listdir(path_with_photos)

    photos = []
    c = 0
    for file in files:
        file_path = os.path.join(path_with_photos, file)
        file_path_out = os.path.join(dir_out, f"nr{c}-{file}")
        photo = threading.Thread(target = fill_og_with_small, args=(file_path, file_path_out, 40, 2048, 2048, "grzesiu.png" ))
        photos.append(photo)
        photo.start()
        c += 1
        print(f"watek {c}")
    # for photo in photos:
    #     photo.join()
    #     print(f"koniec watku {c}")

if __name__ == '__main__':

    begin = time.time()
    fill_all_photos(os.path.join(os.getcwd(), "out"))
    end = time.time()
    print(f"Time: {end-begin}")
# import multiprocessing
# import time
# from multiprocessing import Queue

# def jobConsumer(queue):
#     while True:
#         msg = queue.get()
#         if msg == 'DONE':
#             break
#     print("Consumer done")
        
# def jobProducer(queue,number):
#     for i in range(number):
#         queue.put(64*"")
#     queue.put('DONE')
#     print("Producer done")
    
# def test():
#     for number in [10**4, 10**5, 10**6]:
#         queue = Queue()
        
#         consumer = multiprocessing.Process(target=jobConsumer, args=(queue,))
#         consumer.start()
        
#         begin = time.time()
#         jobProducer(queue, number)
#         consumer.join()
        
#         end = time.time()
#         print(f"Number of messages: {number}, Time taken: {end - begin:.2f} seconds")
        
# if __name__ == '__main__':
#     test()

from PIL import Image

img = Image.open("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/test.png").convert("RGB")
pixels = img.load()
cols, rows = img.size

tSize = 8
s = tSize * tSize

for i in range((int)(cols/tSize)):
    for j in range((int)(rows/tSize)):
        r, g, b = (0,0,0)

        for x in range(tSize):
            for y in range(tSize):
                rPx, gPx, bPx = pixels[i*tSize + x, j*tSize + y]

                r += rPx
                g += gPx
                b += bPx

        r = (int)(r/s)
        g = (int)(g/s)
        b = (int)(b/s)

        for x in range(tSize):
            for y in range(tSize):
                pixels[i*tSize + x, j*tSize + y] = (r,g,b)
        
img.save(f"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/tile_{tSize}.png")
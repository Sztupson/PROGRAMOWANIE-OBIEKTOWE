import threading
import time
import random

mylist = []

def job(n):
    mylist.append(n)
    v = 0
    for i in range(10000):
        v += 1
    print(f"Worker number {n}")
    print(len(mylist))
    print(mylist)

def test():
    workers =[]
    begin = time.time()

    for i in range(10):
        worker = multiprocessing.Process(target=job,args=())
        workers.append()
        worker.st

    end = time.time()
    print("Done")
    print(f"Working time {end-begin}s")

if __name__ == "__main__":
    test()
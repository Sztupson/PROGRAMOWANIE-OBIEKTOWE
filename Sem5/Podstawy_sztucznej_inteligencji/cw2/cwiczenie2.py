import tkinter as tk
import sys

file = sys.argv[1]

root = tk.Tk()

def hash_map(file):
    with open(file) as f:
        map_list = [line.strip("\n") for line in f]

    nodes_count = int(map_list[0])

    for i in range(1, nodes_count+1):
        coordinates = map_list[i]
        x = coordinates.split()

        coords_map = {}
        coords_map[i] = x
        for klucz, wartosc in coords_map.items():
            print(klucz, wartosc)

    for i in range(nodes_count+2, 2*nodes_count+1):
        neighbours = map_list[i]
        x = neighbours.split()

        neigbours_map = {}
        neigbours_map[x[0]] = x[1:]
        for klucz, wartosc in neigbours_map.items():
            print(klucz, wartosc)



hash_map(file)
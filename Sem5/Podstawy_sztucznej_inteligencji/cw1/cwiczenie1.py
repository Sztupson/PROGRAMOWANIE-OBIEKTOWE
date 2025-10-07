
import sys

file = sys.argv[1]   # NAZWA MAPY
# start = sys.argv[2]
# finish = sys.argv[3]
# algorithm = sys.argv[4]

# if algorithm == "BFS" or algorithm == "DFS":
#     print("Wybrano algorytm:", algorithm)
# else:
#     print("Niepoprawna nazwa algorytmu.")
#     sys.exit() 


# def load_map(file):
#     with open(file, encoding="utf-8") as f:
#         mapa = f.read().strip()
#         print(mapa)
#     return mapa

def load_map(file):
    with open(file, encoding="utf-8") as f:
        mapa = [line.strip("\n") for line in f]
    print(mapa)
    return mapa


def translate_unicode():
    pass


# def check_map_size():
#     for row in range (0,10):

#     for j in range (0,20):


moves = {
    "\u253C": ["up", "down", "right", "left"],  # ┼
    "\u2510": ["down", "left"],                 # ┐
    "\u2524": ["up", "down", "left"],           # ┤
    "\u2575": ["up"],                           # ╵
    "\u2502": ["up", "down"],                   # │
    "\u2518": ["up", "left"],                   # ┘
    "\u2534": ["up", "right", "left"],          # ┴
    "\u2577": ["down"],                         # ╷
    "\u2500": ["right", "left"],                # ─
    "\u2514": ["up", "right"],                  # └
    "\u251C": ["up", "down", "right"],          # ├
    "\u2574": ["left"],                         # ╴
    "\u0020": [],                               # (spacja - brak)
    "\u250C": ["down", "right"],                # ┌
    "\u252C": ["down", "right", "left"],        # ┬
    "\u2576": ["right"]                         # ╶
}



load_map(file)

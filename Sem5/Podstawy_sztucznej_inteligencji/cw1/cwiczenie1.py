
import sys
import time


# file = sys.argv[1]  # NAZWA MAPY
# start = sys.argv[2] # koordynaty startowe
# finish = sys.argv[3] # koordynaty końca
# algorithm = sys.argv[4] # rodzaj algorytmu [BFS/DFS]

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
RESET = "\033[0m"


# moves = {
#     "\u253C": ["up", "down", "right", "left"],  # ┼
#     "\u2510": ["down", "left"],                 # ┐
#     "\u2524": ["up", "down", "left"],           # ┤
#     "\u2575": ["up"],                           # ╵
#     "\u2502": ["up", "down"],                   # │
#     "\u2518": ["up", "left"],                   # ┘
#     "\u2534": ["up", "right", "left"],          # ┴
#     "\u2577": ["down"],                         # ╷
#     "\u2500": ["right", "left"],                # ─
#     "\u2514": ["up", "right"],                  # └
#     "\u251C": ["up", "down", "right"],          # ├
#     "\u2574": ["left"],                         # ╴
#     "\u0020": [],                               # (spacja - brak)
#     "\u250C": ["down", "right"],                # ┌
#     "\u252C": ["down", "right", "left"],        # ┬
#     "\u2576": ["right"]                         # ╶
# }
moves = {
    "┼": ["down", "up", "right", "left"],
    "│": ["down", "up"],
    "┬": ["down", "right", "left"],
    "┴": ["up", "right", "left"],
    "├": ["up", "down", "right"],
    "┤": ["up", "down", "left"],
    "┐": ["down", "left"],
    "└": ["up", "right"],
    "┌": ["down", "right"],
    "┘": ["up", "left"],
    "─": ["right", "left"],
    "╵": ["up"],
    "╷": ["down"],
    "╴": ["left"],
    "╶": ["right"],
    " ": []
}




directions = {
    "up": (-1, 0),
    "down": (1, 0),
    "left": (0, -1),
    "right": (0, 1)
}


def load_map(file):
    with open(file, encoding="utf-8") as f:
        mapa = [list(line.rstrip("\n")) for line in f]
    maxlen = max(len(row) for row in mapa)
    for row in mapa:
        while len(row) < maxlen:
            row.append(" ")
    return mapa

def check_map_size(mapa):
    rows = len(mapa)
    columns = len(mapa[0])
    return rows, columns

def print_map(mapa, start, finish, visited, queue):
    rows, columns = check_map_size(mapa)
    for i in range(rows):
        for j in range(columns):
            symbol = mapa[i][j]
            position = (i, j)

            if position == start:
                print(RED + symbol + RESET, end="")
            elif position == finish:
                print(BLUE + symbol + RESET, end="")
            elif position in visited:
                print(GREEN + symbol + RESET, end="")
            elif position in queue:
                print(YELLOW + symbol + RESET, end="")
            else:
                print(symbol, end="")
        print()
    print()

def neighbours(mapa, x, y):
    rows, columns = check_map_size(mapa)
    result = []
    if mapa[x][y] not in moves:
        return result
    
    # mapa[x][y] - wczytanie symbolu np: ┼
    # wczytanie moves z symbolu - moves[mapa[x][y]]
    for dirs in moves[mapa[x][y]]: 
        dir_x, dir_y = directions[dirs]
        new_x = x + dir_x
        new_y = y + dir_y

        # nie wyjdziemy poza granice mapy jeżeli na granicach byłyby bloki typu: ┼
        if (0 <= new_x < rows and 0 <= new_y < columns):
            opposites = {"up": "down", "down": "up", "left": "right", "right": "left"}
            opposite = opposites[dirs]

            if (opposite in moves.get(mapa[new_x][new_y], [])):
                result.append((new_x, new_y))
    return result

def BFS(mapa, start, finish):
    visited = [start]
    queue = [start]
    steps = 0

    while queue:
        steps += 1
        current = queue.pop(0)
        
        print("\033c", end="")
        print_map(mapa, start, finish, visited, queue)
        time.sleep(0.05)

        if current == finish:
            print(f"Dotarto do celu w {steps} krokach." + RESET)
            return True

        for n in neighbours(mapa, current[0], current[1]):
            if n not in visited and n not in queue:
                queue.append(n)
        if current not in visited:
            visited.append(current)


def DFS(mapa, start, finish):
    visited = []
    queue = [start]
    steps = 0

    while queue:
        print("\033c", end="")
        print_map(mapa, start, finish, visited, queue)
        time.sleep(0.05)

        current = queue.pop()
        steps += 1

        if current == finish:
            print(f"Dotarto do celu w {steps} krokach." + RESET)
            return True
        if current not in visited:
            visited.append(current)
            for n in neighbours(mapa, current[0], current[1]):
                # if n not in visited and n not in queue:
                #     queue.append(n)
                    queue.append(n)

def main():
    mapa = load_map(sys.argv[1])
    rows, columns = check_map_size(mapa)

    start1, start2 = input(f"Podaj współrzędne startowe (rozmiar mapy: {rows}x{columns}): ").split(',')
    start1, start2 = int(start1), int(start2)
    if(start1 >= rows or start1 < 0 or start2 >= columns or start2 < 0):
        print("Niepoprawne współrzędne.")
        sys.exit()

    end1, end2 = input(f"Podaj współrzędne końcowe (rozmiar mapy: {rows}x{columns}): ").split(',')
    end1, end2 = int(end1), int(end2)
    if(end1 >= rows or end1 < 0 or end2 >= columns or end2 < 0):
        print("Niepoprawne współrzędne.")
        sys.exit()

    algorithm = input("Podaj nazwę algorytmu(BFS/DFS): ").strip().upper()
    if (algorithm == "DFS" or algorithm == "BFS"):
        print(f"Wybrano algorytm: {algorithm}")
    else:
        sys.exit()

    start = (start1, start2)
    finish = (end1, end2)

    if algorithm == "BFS":
        BFS(mapa, start, finish)
    elif algorithm == "DFS":
        DFS(mapa, start, finish)

if __name__ == "__main__":
    main()
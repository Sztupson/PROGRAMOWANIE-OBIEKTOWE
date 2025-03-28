# Sortowanie plików

## Etap I
Zbiór danych: 7,3,5, 2,1,8, 3,4,6

Podział:
- plik I: 7,3,5
- plik II: 2,1,8
- plik III: 3,4,6

## Etap II
Sortowanie plików:
- read(plik I) -> sort -> plik I: 3,5,7
- read(plik I) -> sort -> plik I: 1,2,8
- read(plik I) -> sort -> plik I: 3,4,6

## Etap III
Łączenie plików:

- plik I: 3,5,7
- plik II: 1,2,8
- **plik I_II**: 1, 2, 3 , 5, 7, 8

Następnie **plik I_II** + **plik I_II__III** -> wszystko posortowane.

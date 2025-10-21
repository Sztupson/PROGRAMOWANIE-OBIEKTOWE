<<<<<<< HEAD
# Dokumentacja – Odtwarzacz muzyki z obsługą strategii odtwarzania

## Opis ogólny
=======
# 🎵 Dokumentacja – Odtwarzacz muzyki z obsługą strategii odtwarzania

## 📌 Opis ogólny
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

Ten projekt implementuje prosty **odtwarzacz muzyki** w języku C++ z trzema trybami odtwarzania:  
- **Normalny** (odtwarzanie kolejnych utworów),
- **Repeat** (powtarzanie tego samego utworu),
- **Shuffle** (losowe wybieranie utworu).

Użytkownik może dynamicznie zmieniać sposób odtwarzania. Wszystkie operacje wykonywane są przez jedną globalną instancję odtwarzacza, co zapewnia spójność działania.

<<<<<<< HEAD
Program wykorzystuje dwa **wzorce projektowe**:
- `Strategy` – do definiowania i wybierania trybu odtwarzania,
- `Singleton` – do zarządzania pojedynczą instancją odtwarzacza.

## Struktura klas
=======
Program wykorzystuje dwa popularne **wzorce projektowe**:
- `Strategy` – do definiowania i wybierania trybu odtwarzania,
- `Singleton` – do zarządzania pojedynczą instancją odtwarzacza.

---

## 🧱 Struktura klas
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

### `PlaybackType` – interfejs strategii odtwarzania (**Strategy Pattern**)

```cpp
class PlaybackType {
public:
    virtual ~PlaybackType() = default;
    virtual int getNextIndex(size_t currentIndex, size_t size) = 0;
    virtual std::string name() const = 0;
};
```

### Klasy implementujące `PlaybackType`

<<<<<<< HEAD
#### `NormalPlayback`
=======
#### 🔁 `NormalPlayback`
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

Odtwarza kolejne utwory w kolejności. Po osiągnięciu końca wraca do początku (cykliczne odtwarzanie).

```cpp
int getNextIndex(size_t currentIndex, size_t size) override {
    return (currentIndex + 1) % size;
}
```

<<<<<<< HEAD
#### `RepeatPlayback`
=======
#### 🔂 `RepeatPlayback`
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

Zatrzymuje się na bieżącym utworze i powtarza go bez końca.

```cpp
int getNextIndex(size_t currentIndex, size_t size) override {
    return currentIndex;
}
```

<<<<<<< HEAD
#### `ShufflePlayback`
=======
#### 🔀 `ShufflePlayback`
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

Losowo wybiera inny utwór niż aktualnie odtwarzany (jeśli playlista ma więcej niż 1 element).

```cpp
int getNextIndex(size_t currentIndex, size_t size) override {
    size_t next = currentIndex;
    while (next == currentIndex && size > 1) {
        next = rand() % size;
    }
    return next;
}
```

<<<<<<< HEAD

### `MusicPlayer` – główny odtwarzacz (**Singleton Pattern**)
=======
---

### 🎮 `MusicPlayer` – główny odtwarzacz (**Singleton Pattern**)
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

Główna klasa zarządzająca playlistą, trybem odtwarzania i interakcją z użytkownikiem.

#### Składowe:
- `std::vector<std::string> playlist` – lista utworów,
- `size_t currentIndex` – indeks aktualnego utworu,
- `PlaybackType* strategy` – aktualna strategia odtwarzania,
- `static MusicPlayer* instance` – jedyna instancja klasy.

#### Publiczne metody:
- `static MusicPlayer* getInstance()` – zwraca jedyną instancję klasy,
- `void setStrategy(PlaybackType* strat)` – ustawia strategię odtwarzania,
- `void addSong(const std::string& song)` – dodaje utwór do playlisty,
- `void play() const` – odtwarza bieżący utwór,
- `void next()` – przechodzi do kolejnego utworu wg strategii.

<<<<<<< HEAD


## Uzasadnienie wzorców projektowych

### Strategy 

**Cel:** Umożliwia dynamiczną zmianę sposobu działania funkcji `next()` bez potrzeby modyfikowania klasy `MusicPlayer`.

- Rozdzielenie logiki odtwarzacza i logiki wyboru utworu,
- Zgodność z zasadą Open/Closed – łatwo dodać nowe strategie,

### Singleton 

**Cel:** Zapewnia istnienie tylko jednej instancji `MusicPlayer`.

=======
---

## 🤖 Uzasadnienie wzorców projektowych

### ✅ Strategy Pattern

**Cel:** Umożliwia dynamiczną zmianę sposobu działania funkcji `next()` bez potrzeby modyfikowania klasy `MusicPlayer`.

**Korzyści:**
- Rozdzielenie logiki odtwarzacza i logiki wyboru utworu,
- Zgodność z zasadą Open/Closed – łatwo dodać nowe strategie,
- Większa modularność i testowalność.

### ✅ Singleton Pattern

**Cel:** Zapewnia istnienie tylko jednej instancji `MusicPlayer`.

**Korzyści:**
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19
- Globalny punkt dostępu,
- Zapobiega błędom związanym z wieloma instancjami,
- Przejrzyste zarządzanie stanem aplikacji.

---

<<<<<<< HEAD



=======
## 🧪 Przykładowe użycie (`main()`)

```cpp
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    MusicPlayer* player = MusicPlayer::getInstance();

    player->addSong("Imagine - John Lennon");
    player->addSong("Billie Jean - Michael Jackson");
    player->addSong("Bohemian Rhapsody - Queen");
    player->addSong("Shape of You - Ed Sheeran");

    NormalPlayback normal;
    RepeatPlayback repeat;
    ShufflePlayback shuffle;

    player->setStrategy(&normal);
    player->play();
    player->next();
    player->next();

    std::cout << "\nZmiana trybu na Repeat:\n";
    player->setStrategy(&repeat);
    player->next();
    player->next();

    std::cout << "\nZmiana trybu na Shuffle:\n";
    player->setStrategy(&shuffle);
    player->next();
    player->next();

    return 0;
}
```

---

## 🚀 Możliwe rozszerzenia

- Dodanie nowych trybów: `ReversePlayback`, `FavoritesOnly`, `SmartShuffle`,
- Możliwość usuwania lub edytowania utworów z playlisty,
- Historia odtwarzania,
- Obsługa GUI (np. z użyciem Qt) lub interfejsu tekstowego (CLI),
- Lepsze losowanie: zastąpienie `rand()` przez `std::mt19937`.

---

## ⚠️ Uwagi techniczne

- Singleton nie jest obecnie bezpieczny dla wątków (brak synchronizacji),
- W przypadku użycia strategii dynamicznie alokowanych (np. przez `new`), należałoby zadbać o ich zwolnienie (tu są na stosie),
- W trybie shuffle przy jednej piosence może wystąpić nieskończona pętla (zapętlone losowanie tego samego indeksu).

---

## ✅ Podsumowanie

Program demonstruje dobre praktyki programowania obiektowego:
- zastosowanie wzorców projektowych `Strategy` i `Singleton`,
- modularność i rozszerzalność kodu,
- klarowny podział odpowiedzialności.

Kod jest gotowy do rozbudowy o nowe funkcje oraz integracji z interfejsem użytkownika.
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

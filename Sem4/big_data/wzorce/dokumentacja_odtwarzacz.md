# Dokumentacja – Odtwarzacz muzyki z obsługą strategii odtwarzania

## Opis ogólny

Ten projekt implementuje prosty **odtwarzacz muzyki** w języku C++ z trzema trybami odtwarzania:  
- **Normalny** (odtwarzanie kolejnych utworów),
- **Repeat** (powtarzanie tego samego utworu),
- **Shuffle** (losowe wybieranie utworu).

Użytkownik może dynamicznie zmieniać sposób odtwarzania. Wszystkie operacje wykonywane są przez jedną globalną instancję odtwarzacza, co zapewnia spójność działania.

Program wykorzystuje dwa **wzorce projektowe**:
- `Strategy` – do definiowania i wybierania trybu odtwarzania,
- `Singleton` – do zarządzania pojedynczą instancją odtwarzacza.

## Struktura klas

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

#### `NormalPlayback`

Odtwarza kolejne utwory w kolejności. Po osiągnięciu końca wraca do początku (cykliczne odtwarzanie).

```cpp
int getNextIndex(size_t currentIndex, size_t size) override {
    return (currentIndex + 1) % size;
}
```

#### `RepeatPlayback`

Zatrzymuje się na bieżącym utworze i powtarza go bez końca.

```cpp
int getNextIndex(size_t currentIndex, size_t size) override {
    return currentIndex;
}
```

#### `ShufflePlayback`

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


### `MusicPlayer` – główny odtwarzacz (**Singleton Pattern**)

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



## Uzasadnienie wzorców projektowych

### Strategy 

**Cel:** Umożliwia dynamiczną zmianę sposobu działania funkcji `next()` bez potrzeby modyfikowania klasy `MusicPlayer`.

- Rozdzielenie logiki odtwarzacza i logiki wyboru utworu,
- Zgodność z zasadą Open/Closed – łatwo dodać nowe strategie,

### Singleton 

**Cel:** Zapewnia istnienie tylko jednej instancji `MusicPlayer`.

- Globalny punkt dostępu,
- Zapobiega błędom związanym z wieloma instancjami,
- Przejrzyste zarządzanie stanem aplikacji.

---





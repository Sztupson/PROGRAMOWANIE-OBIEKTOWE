#include <iostream>
#include <cstring>

class Notatnik {};
class Owca {
public:
    Owca() : n(new Notatnik), hp(100) {}; // konstruktor
    ~Owca() { delete n; }; // destruktor
private:
    Notatnik *n;
int hp;
};

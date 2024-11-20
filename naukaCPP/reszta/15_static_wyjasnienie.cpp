#include <iostream>

class MojaKlasa {
public:
    static int licznikObiektow;
    MojaKlasa() {
        licznikObiektow++;
    }
};

int MojaKlasa::licznikObiektow = 0;  // Definicja zmiennej statycznej

int main() {
    MojaKlasa obj1, obj2;
    MojaKlasa obj3;
    std::cout << "Liczba obiektow: " << MojaKlasa::licznikObiektow << std::endl;
    return 0;
}
// static jest używane w klasach, aby zachować jedną zmienną dla wszystkich obiektów.
#include <iostream>
#include <cmath>

/* 
 - Konstruktor nie ma typu return
 - Ma taką samą nazwę jak klasa
 - Może posiadać parametry (ale może być również pusty)
 - Używany często, aby zainicjalizować zmienne klasy
*/

// Konstruktor NIE MOŻE znajdować się w polu private:

class Cylinder {
public:
    Cylinder() {    //Taki pusty konstruktor zostanie zawsze
                    //zainicjalizowany przez klasę, jeżeli
    }               //nie zdefiniujemy własnego konstruktora
    

    Cylinder() {
        base_radius = 3.0;
        height = 2.0;
    }
    Cylinder(double _base_radius, double _height)
            : base_radius(_base_radius), height(_height) {
                amount_of_objects++;
                std::cout << "\nLiczba obiektow w drugim konstruktorze, zainicjalizowana wartościa 5: " <<
                          amount_of_objects <<  std::endl;
            }


    double volume() {
        return M_PI * base_radius * base_radius * height;
    }

private:
    double base_radius;
    double height;
    static int amount_of_objects;
};

int Cylinder::amount_of_objects = 5;

int main() {  
    Cylinder c1; // Korzystanie z pierwszego konstruktora 
                 // - bazowe wartości 3.0 i 2.0
    Cylinder c2(4.0, 5.0); 
                 // Korzystanie z drugiego konstruktora w
                 // celu wprowadzenia własnych wartości
                 // mamy w ten sposób możliwość modyfikowania
                 // zmiennych prywatnych

    std::cout << "Volume: " << c1.volume() << std::endl;
    std::cout << "Volume2: " << c2.volume() << std::endl;
    
    return 0;
}
#include <iostream>
#include <cmath>

class Cylinder {
public:
    Cylinder() = default;      
        /*
        Używamy takiego wyrażenia, gdy utworzyliśmy już własny
        konstruktor, ale chcemy skorzystać z takiego jaki program
        by utworzył jeżeli nie zdefiniowalibyśmy żadnego konstruktora
        */
 

    Cylinder(double _base_radius, double _height)
            : base_radius(_base_radius), height(_height) {
            }

    double volume() {
        return M_PI * base_radius * base_radius * height;
    }

private:
    double base_radius = 1.0;  //Tych wartości użyje konstruktor default
    double height = 1.0;
};

int main() {  
    Cylinder c1;            // Konstruktor default
    Cylinder c2(4.0, 5.0);  // Konstruktor własny

    std::cout << "Volume: " << c1.volume() << std::endl;
    std::cout << "Volume2: " << c2.volume() << std::endl;
    
    return 0;
}
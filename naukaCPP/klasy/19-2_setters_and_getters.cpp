#include <iostream>
#include <cmath>
/*
Settery i gettery używane są aby móc modyfikować lub sprawdzać
wartości zmiennych w klasie spoza klasy.
*/
class Cylinder {
public:
    Cylinder(double _base_radius, double _height)
            : base_radius(_base_radius), height(_height) {}
    //getters
    double get_base_radius() {
        return base_radius;
    }
    double get_height() {
        return height;
    }

    //setters
    void set_base_radius(double _base_radius) {
        base_radius = _base_radius;
    } 
    void set_height(double _height) {
        height = _height;
    } 
    


    double volume() {
        return M_PI * base_radius * base_radius * height;
    }


private:
    double base_radius = 1.0;
    double height = 1.0;
};

int main() {        
    Cylinder c1(4.0, 5.0); 

    std::cout << "Base Radius: " << c1.get_base_radius() << std::endl;
    std::cout << "Volume1: " << c1.volume() << "\n================"<<std::endl ;
    c1.set_base_radius(3.9);
    std::cout << "Base Radius2: " << c1.get_base_radius() << std::endl;
    std::cout << "Volume2: " << c1.volume() << "\n================"<<std::endl ;


    std::cout << "Height: " << c1.get_height() << std::endl;
    std::cout << "Volume3: " << c1.volume() << "\n================"<<std::endl ;
    c1.set_height(2.5);
    std::cout << "Height2: " << c1.get_height() << std::endl;
    std::cout << "Volume4: " << c1.volume() << "\n================"<<std::endl ;
    
    return 0;
}
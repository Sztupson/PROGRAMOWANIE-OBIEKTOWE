#include <iostream>
#include <cmath>

class Cylinder {
public:
    Cylinder(double _base_radius, double _height)
            : base_radius(_base_radius), height(_height) {}
    double get_base_radius() {
        return base_radius;
    }
    double get_height() {
        return height;
    } 
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

    Cylinder c(10,10);
    c.volume();

    Cylinder* ptr_c = &c;

    //std::cout << "Volume: " << ptr_c.volume() << std::endl; 
    // takie wywołanie nie zadziała

    std::cout << "Volume: " << (*ptr_c).volume() << std::endl; 
    //Takie wywołanie zadziała, jednak trzeba korzystać z dereferencji co może być niewygodne

    std::cout << "Volume: " << ptr_c->volume() << std::endl; 
    //Takie wywołanie jest takie samo jak nasze poprzednie wywołanie jednak nie trzeba
    //korzystać z dereferencji i jest to bardziej przejrzyste

    // Create cylinder object throught the new operator
    Cylinder* ptr_c2 = new Cylinder(100,2); //Trzeba bedzie użyć delete!
    std::cout << "\nVolume: " << ptr_c2->volume() << std::endl; 
    std::cout << "Base radius2 : " << ptr_c2->get_base_radius() << std::endl;


    delete ptr_c2;
    return 0;
}
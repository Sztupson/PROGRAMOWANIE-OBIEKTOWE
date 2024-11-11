#include <iostream>
#include <cmath>

class Cylinder {
public: // jeżeli nie ma public, wszystko przypisywane jest jako
        // private, przez co nie mozna dostać się do tych
        // funkcji w int main
    
    // Functions (methods)
    double volume() {
        return M_PI * base_radius * base_radius * height;
    }

    // Member variables || they can never be references
    // only normal variables or pointers
    double base_radius;
    double height;  
};


int main() {  

    Cylinder c1; // object
    std::cout << c1.volume() << std::endl;
    
    c1.base_radius = 1.0;
    c1.height = 1.0;
    std::cout << c1.volume() << std::endl;

}
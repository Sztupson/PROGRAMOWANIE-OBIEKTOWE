#include <iostream> 

const int Pen{10};
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60};


int main() {  

int tool {Eraser};
    switch (tool)
    {
        case Pen: {
            std::cout << "Active tool is Pen" << std::endl;
        }
        break;
        case Marker: {
            std::cout << "Active tool is Marker" << std::endl;
        }
        break;


        case Circle:
        case Rectangle:
        case Eraser: {
            std::cout << "Drawing shapes" << std::endl;
        }
            break;
        
        
        case Ellipse: {
            std::cout << "Active tool is Ellipse" << std::endl;
        }
        break;
    
        default: {
            std::cout << "No match found" << std::endl;
        }
            break;
    }
    std::cout << "Switch ended" <<std::endl;
}  
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>

template<typename T>
class Shape {
public:
    virtual T area() const = 0;
    virtual ~Shape() = default;
};


template<typename T>
class Rectangle : public Shape<T> {
private:
    T width, height;
public:
    Rectangle(T width_, T height_) : width(width_), height(height_) { 
        if (width <= 0 || height <=0) { throw std::invalid_argument("Podaj dodatnie wymiary."); }
    }

    T area() const override { return width * height; }
};


template<typename T>
class Square : public Rectangle<T> {
public:
    Square(T length) : Rectangle<T>(length, length) {
        if(length <=0) { throw std::invalid_argument("Podaj dodatnie wymiary."); }
    }
};


int main() {
    try {
        Rectangle<int> rectangle1(2, 4);
        Rectangle<double> rectangle2(2.3, 4.5);
        std::cout << "Pole prostokata int: " << rectangle1.area() << std::endl;
        std::cout << "Pole prostokata double: " << rectangle2.area() << std::endl;


        Square<int> square1(2);
        Square<double> square2(1.2);
        std::cout << "Pole kwadratu int: " << square1.area() << std::endl;
        std::cout << "Pole kwadratu double: " << square2.area() << std::endl;

        // Square<double> err_square(-2);
        Rectangle<int> err_rectangle(0, 4);

    } catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }

    return 0;
}



#include <iostream>
#include <cmath>


class Shape {
public:
~Shape();
    virtual double circum() = 0;
    virtual double area() = 0;
};

class Rectangular : public Shape {
public:
    Rectangular(double w, double h) : width(w), height(h) {};
    double circum();
    double area();
private:
    double width, height;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {};
    double circum() { return 2 * M_PI * radius; };
    double area() { return M_PI * radius * radius; };
private:
    double radius;
};

void print(Shape &s) {
    std::cout << "Obwód: " << s.circum() << ", pole: " << s.area() << std::endl;
};

int main() {
Rectangular rect(20,10);
Circle circle(20);
print(rect);
print(circle);


Shape &shape = circle;
Circle &ref = dynamic_cast<Circle&>(shape);
return 0;
}
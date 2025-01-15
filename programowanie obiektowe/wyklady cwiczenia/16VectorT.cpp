#include <iostream>
#include <cmath>
#include <iomanip>

class Vector {
public:
    virtual ~Vector();
    virtual double length() const = 0;
    virtual void normalize() = 0;
};


template<typename T>
class Vector2D : public Vector<T> {
protected:
    T x,y;
public:
    Vector2D(T _x, T _y) : x(_x), y(_y) {}
    
    double length() const override {
        double len = std::sqrt(x * x  +  y * y);
        return len;
    }
    void normalize() override {
        double len = length();
        x = x/len;
        y = y/len;
    }
    friend std::ostream& operator<< (std::ostream& output, const Vector2D& vec) {
        output << "Wektor2D Współrzędne: (" << vec.x << ", " << vec.y << "). dlugosc: " 
               << vec.length() << "po normalizacji: ("
               << vec.normalize() << vec.x << ", " << vec.y << vec.normalize(vec.y) << "). Dlugosc: "
               << vec.length() ;
               return output;
    }
};


template<typename T>
class Vector3D : public Vector2D<T> {
private:
    T z;
public:
    Vector3D(T _x, T _y, T _z) : Vector2D<T>(_x, _y), z(_z) {}
    double length() const override {
        double len = std::sqrt(this->x * this->x  +  this->y * this->y +  z*z);
        return len;
    }
    void normalize() override {
        double len = length();
        this->x = this->x/len;
        this->y = this->y/len;
        z = z/len;
    }
    friend std::ostream& operator<< (std::ostream& output, const Vector3D& vec) {
        output << "Wektor3D: Współrzędne: (" << vec.x << ", " << vec.y << ", " << vec.z << "), dlugosc:"
               << vec.length() << "po normalizacji: (" 
               << vec.normalize() << vec.x << ", " <<  vec.y << ", " << vec.z << "), dlugosc:"
               << vec.length();
               return output;
    }
    
};

int main() {
    Vector2D v2(3, 5);
    Vector3D v3(3.4, 5.5, 4.0);

    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;


}
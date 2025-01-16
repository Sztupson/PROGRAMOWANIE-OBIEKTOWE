#include <iostream>
#include <cmath>
#include <iomanip>

template <typename T>
class Vector {
public:
    virtual ~Vector() = default;
    virtual double length() const = 0;
    virtual void normalize() = 0;
};


template<typename T>
class Vector2D : public Vector<T> {
protected:
    T x,y;
public:
    Vector2D(T _x, T _y) : x(_x), y(_y) {}
    
    double length() const override { return std::sqrt(x * x  +  y * y); }
    void normalize() override {
        double len = length();
        if(len > 0) {
            x = x/len;
            y = y/len;
        } else {
            std::cout << "Dlugosc wektora równa 0, nie można normalizować wektora 2D.\n";
        }
    }
    friend std::ostream& operator<< (std::ostream& output, const Vector2D& vec) {
        output << "Wektor2D \nWspółrzędne: (" << vec.x << ", " << vec.y << ").\nDlugosc: " 
               << vec.length() << "\n";
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
        if(len > 0) {
            this->x = this->x/len;
            this->y = this->y/len;
            z = z/len;
        } else {
            std::cout << "Dlugosc wektora równa 0, nie można normalizować wektora 2D.\n";
        }
    }
    friend std::ostream& operator<< (std::ostream& output, const Vector3D& vec) {
        output << "Wektor3D: \nWspółrzędne: (" << vec.x << ", " << vec.y << ", " << vec.z << "),\nDlugosc:"
               << vec.length() << "\n";
               return output;
    }
    
};

int main() {
    Vector2D v2(0, 0);
    Vector3D v3(3.4, 5.5, 4.0);

    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;

    std::cout << "#########################\nWektory po normalizacji:\n#########################\n\n";

    v2.normalize();
    v3.normalize();
    
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;


}
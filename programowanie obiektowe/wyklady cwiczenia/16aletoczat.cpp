#include <iostream>
#include <cmath>
#include <iomanip>

// Interfejs (klasa bazowa)
template<typename T>
class Vector {
public:
    virtual ~Vector() = default;
    virtual double length() const = 0; // Wirtualna metoda do obliczenia długości
    virtual void normalize() = 0;     // Wirtualna metoda do normalizacji
};

// Klasa Vector2D dziedzicząca po Vector<T>
template<typename T>
class Vector2D : public Vector<T> {
protected:
    T x, y; // Współrzędne wektora 2D
public:
    Vector2D(T _x, T _y) : x(_x), y(_y) {}

    // Implementacja metody do obliczenia długości wektora
    double length() const override {
        return std::sqrt(x * x + y * y);
    }

    // Implementacja metody do normalizacji wektora
    void normalize() override {
        double len = length();
        if (len > 0) {
            x = static_cast<T>(x / len);
            y = static_cast<T>(y / len);
        }
    }

    // Operator strumieniowy do wyświetlania wektora
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "Wektor 2D: (" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

// Klasa Vector3D dziedzicząca po Vector2D<T>
template<typename T>
class Vector3D : public Vector2D<T> {
private:
    T z; // Trzecia współrzędna wektora 3D
public:
    Vector3D(T _x, T _y, T _z) : Vector2D<T>(_x, _y), z(_z) {}

    // Implementacja metody do obliczenia długości wektora
    double length() const override {
        return std::sqrt(this->x * this->x + this->y * this->y + z * z);
    }

    // Implementacja metody do normalizacji wektora
    void normalize() override {
        double len = length();
        if (len > 0) {
            this->x = static_cast<T>(this->x / len);
            this->y = static_cast<T>(this->y / len);
            z = static_cast<T>(z / len);
        }
    }

    // Operator strumieniowy do wyświetlania wektora
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
        os << "Wektor 3D: (" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }
};

// Funkcja główna testująca działanie klas
int main() {
    // Test klasy Vector2D
    Vector2D<int> v2(3, 4);
    std::cout << v2 << "\n";
    std::cout << "Długość: " << v2.length() << "\n";
    v2.normalize();
    std::cout << "Po normalizacji: " << v2 << "\n";

    // Test klasy Vector3D
    Vector3D<double> v3(1.0, 2.0, 2.0);
    std::cout << v3 << "\n";
    std::cout << "Długość: " << std::fixed << std::setprecision(2) << v3.length() << "\n";
    v3.normalize();
    std::cout << "Po normalizacji: " << v3 << "\n";

    return 0;
}

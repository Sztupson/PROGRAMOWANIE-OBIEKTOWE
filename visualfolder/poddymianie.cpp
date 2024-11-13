#include <iostream>

class Car {
public:
    Car(const std::string &_man, const std::string &_mod, const std::string &_vin)
        :  manufacturer(_man), model(_mod), vin(_vin) {}
    void drive() {std::cout<<" twoja stara " << manufacturer << " " << model << " " << vin <<std::endl;};
    void setVin(const std::string &_vin) {this->vin = _vin;};

private:
    std::string manufacturer;
    std::string model;
    std::string vin;
};

class PetrolCar : virtual public Car {
public:
    PetrolCar(const std::string &_man, const std::string &_mod, const std::string &_vin, int _cap)
        :  Car(_man, _mod, _vin), fuelCapacity(_cap) {}
private:
    int fuelCapacity;
};

class ElectricCar : virtual public Car {
public:
    ElectricCar(const std::string &_man, const std::string &_mod, const std::string &_vin, int _cap)
        :  Car(_man, _mod, _vin), batteryCapacity(_cap) {}
private:
    int batteryCapacity;
};

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(const std::string &_man, const std::string &_mod, const std::string &_vin, int _fuelCapacity, int _batteryCapacity)
        :  PetrolCar("twoj ","stary ","1234 ", _fuelCapacity), ElectricCar("twoja ","stara ","321 ", _batteryCapacity), Car(_man, _mod, _vin) {}
};


int main() {
    HybridCar hc("dildo", "vaggins", "123131231313123123", 50, 100);

    hc.drive();

    return 0;
}
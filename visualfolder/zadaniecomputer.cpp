#include <iostream>
#include <string>

class Computer {
private:
    std::string manufacturer;
    std::string model;
    std::string cpu;
    unsigned int ramMemory;
    unsigned int diskMemory;

public:
    Computer(const std::string& _manufacturer, const std::string& _model, const std::string& _cpu, unsigned int _ramMemory, unsigned int _diskMemory)
        : manufacturer(_manufacturer), model(_model), cpu(_cpu), ramMemory(_ramMemory), diskMemory(_diskMemory) {}

    virtual void print() const {
        std::cout << manufacturer << " " << model << " / " << cpu << " / " << ramMemory << " GB RAM / " << diskMemory << " GB DISK" << std::endl;
    }


    void setMenuManufacturer(std::string &newManufacturer) {
        manufacturer = newManufacturer;
    };

    void setModel(std::string &newModel) {
        model = newModel;
    };

    void setCpu(std::string &newCpu) {
        cpu = newCpu;
    };

    void setRamMemory(unsigned int newRamMemory) {
        ramMemory = newRamMemory;
    };

    void setDiskMemory(unsigned int newDiskMemory) {
        diskMemory = newDiskMemory;
    };
};


class Laptop : public Computer {
private:
    unsigned int screen; // inches
    unsigned int battery; // Wh

public:
    Laptop(const Computer &_comp, unsigned int _screen, unsigned int _battery) : Computer(_comp), screen(_screen), battery(_battery) {};

    void print() const {
        Computer::print();
        std::cout << screen << "cali / " << battery << " Wh" << std::endl;
    };


    void setScreen(unsigned int newScreen) {
        screen = newScreen;
    };

    void setBattery(unsigned int newBattery) {
        battery = newBattery;
    };
};

class Desktop : public Computer {
private:
    std::string formFactor;
    std::string psu;
public:
    Desktop(const std::string &_manufacturer, const std::string &_model, const std::string &_cpu, unsigned int _ramMemory, unsigned int _diskMemory, const std::string &_formFactor, const std::string &_psu)
        : Computer(_manufacturer, _model, _cpu, _ramMemory, _diskMemory), formFactor(_formFactor), psu(_psu) {}

    void print() const {
        Computer::print();
        std::cout << formFactor << " / " << psu << " Wh" << std::endl;
    };

    void setFormFactor(std::string newFormFactor) {
        formFactor = newFormFactor;
    };

    void setPsu(std::string newPsu) {
        psu = newPsu;
    };

};

void show(const Computer &computer) {
    computer.print();
};


int main() {
    Computer c("SNSV", "Longitude 555", "i11-1234X", 16, 512);
    Laptop l(c, 15, 50);
    Desktop d("Optimus", "PW-000", "i13-4321X", 96, 4096, "SFF", "550W 80 Plus Gold");


    std::cout << "Specyfikacja komputera:" << std::endl;
    c.print();

    std::cout << "Specyfikacja laptopa:" << std::endl;
    l.print();

    std::cout << "==================\n==================" << std::endl;

    std::cout << "Specyfikacja desktopa:" << std::endl;
    d.print();

    std::cout << "==================\n==================" << std::endl;

    show(c);
    show(l);
    show(d);
    return 0;
}
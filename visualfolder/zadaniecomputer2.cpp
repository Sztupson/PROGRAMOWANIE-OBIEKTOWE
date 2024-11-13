#include <iostream>
#include <string>

// Klasa bazowa Computer
class Computer {
private:
    std::string manufacturer;
    std::string model;
    std::string cpu;
    unsigned int ramMemory; // GB
    unsigned int diskMemory; // GB

public:
    // Konstruktor z listą inicjalizacyjną
    Computer(const std::string &_manufacturer, const std::string &_model, const std::string &_cpu, unsigned int _ramMemory, unsigned int _diskMemory)
        : manufacturer(_manufacturer), model(_model), cpu(_cpu), ramMemory(_ramMemory), diskMemory(_diskMemory) {}

    // Metoda print - wypisuje specyfikację komputera
    virtual void print() const {
        std::cout << manufacturer << " " << model << " / " << cpu << " / " << ramMemory << " GB RAM / " << diskMemory << " GB DISK" << std::endl;
    }

    // Metody set
    void setManufacturer(const std::string &newManufacturer) { manufacturer = newManufacturer; }
    void setModel(const std::string &newModel) { model = newModel; }
    void setCpu(const std::string &newCpu) { cpu = newCpu; }
    void setRamMemory(unsigned int newRamMemory) { ramMemory = newRamMemory; }
    void setDiskMemory(unsigned int newDiskMemory) { diskMemory = newDiskMemory; }

    // Wirtualny destruktor
    virtual ~Computer() = default;
};

// Klasa pochodna Laptop
class Laptop : public Computer {
private:
    unsigned int screen; // inches
    unsigned int battery; // Wh

public:
    // Konstruktor z listą inicjalizacyjną
    Laptop(const Computer &_comp, unsigned int _screen, unsigned int _battery)
        : Computer(_comp), screen(_screen), battery(_battery) {}

    // Metoda print - wypisuje specyfikację laptopa
    void print() const override {
        Computer::print(); // Wywołanie metody print z klasy bazowej
        std::cout << screen << "\" / " << battery << " Wh" << std::endl;
    }

    // Metody set
    void setScreen(unsigned int newScreen) { screen = newScreen; }
    void setBattery(unsigned int newBattery) { battery = newBattery; }
};

// Klasa pochodna Desktop
class Desktop : public Computer {
protected:
    std::string formFactor; // np. "SFF", "Tower"
    std::string psu; // np. "550W 80 Plus Gold"

public:
    // Konstruktor z listą inicjalizacyjną
    Desktop(const std::string &_manufacturer, const std::string &_model, const std::string &_cpu, unsigned int _ramMemory, unsigned int _diskMemory, const std::string &_formFactor, const std::string &_psu)
        : Computer(_manufacturer, _model, _cpu, _ramMemory, _diskMemory), formFactor(_formFactor), psu(_psu) {}

    // Metoda print - wypisuje specyfikację desktopa
    void print() const override {
        Computer::print(); // Wywołanie metody print z klasy bazowej
        std::cout << formFactor << " / " << psu << std::endl;
    }

    // Metody set
    void setFormFactor(const std::string &newFormFactor) { formFactor = newFormFactor; }
    void setPsu(const std::string &newPsu) { psu = newPsu; }
};

// Funkcja show przyjmuje obiekt typu Computer i wywołuje metodę print
void show(const Computer &computer) {
    computer.print();
}

int main() {
    // Tworzenie obiektów klasy Computer, Laptop, Desktop
    Computer c("SNSV", "Longitude 555", "i11-1234X", 16, 512);
    Laptop l(c, 15, 50); // Laptop z konstruktorem przyjmującym obiekt Computer
    Desktop d("Optimus", "PW-000", "i13-4321X", 96, 4096, "SFF", "550W 80 Plus Gold");

    // Wywoływanie metod print
    std::cout << "Specyfikacja komputera:" << std::endl;
    c.print();

    std::cout << "Specyfikacja laptopa:" << std::endl;
    l.print();

    std::cout << "Specyfikacja desktopa:" << std::endl;
    d.print();

    // Wywołanie funkcji show dla każdego z obiektów
    std::cout << "\nWywołanie funkcji show dla obiektu Computer:" << std::endl;
    show(c);

    std::cout << "\nWywołanie funkcji show dla obiektu Laptop:" << std::endl;
    show(l);

    std::cout << "\nWywołanie funkcji show dla obiektu Desktop:" << std::endl;
    show(d);

    return 0;
}

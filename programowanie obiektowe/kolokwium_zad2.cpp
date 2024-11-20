#include <iostream>

class ICommand
{
public:
    ICommand(){
        std::cout << "Wywołano konstruktor ICommand"<<std::endl;
    };
    virtual ~ICommand() {
        std::cout << "Wywołano destruktor ICommand"<<std::endl;
    };
    virtual char getCommand() const = 0;
};

class SystemUptime : public ICommand {
public:
    SystemUptime() {
        std::cout << "Wywołano kostruktor SystemUptime" << std::endl;
    }
    ~SystemUptime() {
        std::cout << "Wywołano destruktor SystemUptime" << std::endl;
    }
    char getCommand() const override {return 'U';}
};

class SystemMemory : public ICommand {
public:
    SystemMemory() { 
        std::cout << "Wywołano kostruktor SystemMemory" << std::endl;
    }
    ~SystemMemory() { 
        std::cout << "Wywołano destruktor SystemMemory" << std::endl;
    }
    char getCommand() const override { return 'M';}
};



void printCommand(const ICommand *c) {
    std::cout << c->getCommand() << std::endl;
}

int main () {
    ICommand *ut = new SystemUptime();
    ICommand *mem = new SystemMemory();

    printCommand(ut);
    printCommand(mem);
    
    delete ut;
    delete mem;

    
    return 0;
}
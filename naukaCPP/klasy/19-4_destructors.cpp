#include <iostream>

class Dog {
public:
    Dog() = default;
    Dog(const std::string& _name, const std::string& _breed, int _p_age) {
        name = _name;
        breed = _breed;
        p_age = new int;
        *p_age = _p_age;
        std::cout << "Wywolano konstruktor dla: " << name << std::endl;
    }
    ~Dog() { 
        delete p_age;
        std::cout << "Wywolano destruktor dla: " << name << std::endl;
    }; // destructor declared


private:
    std::string name;
    std::string breed;
    int* p_age;
};

void some_func(Dog _dog) {}

int main() {  
    Dog dog("Fluffy", "Shepherd", 2);
    some_func(dog);
    
    std::cout << "Done" << std::endl;
    return 0;
}
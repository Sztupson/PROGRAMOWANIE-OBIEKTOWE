#include <iostream>
#include <string>

class Dog {
public:
    Dog() = default;
    Dog(const std::string& _name, const std::string _breed, int _age);
    ~Dog();

    void print() {
        std::cout << "Dog(" << this <<") :  [ Name: " << name << ", breed: " << breed << ", age: " << *p_age << " ]" << std::endl;
    }

    //setters
    /*
    void set_name(std::string name) {
        this->name = name;
    }

    void set_breed(std::string breed) {
        this->breed = breed;
    }

    void set_age(int age) {
        *(this)->p_age = age;
    }
    */

    // chained calls using pointers
    /*
    Dog* set_name(std::string name) {
        this->name = name;
        return this;
    }

    Dog* set_breed(std::string breed) {
        this->breed = breed;
        return this;
    }

    Dog* set_age(int age) {
        *(this)->p_age = age;
        return this;
    }
    */
 // chained calls using references
    Dog& set_name(std::string name) {
        this->name = name;
        return *this;
    }

    Dog& set_breed(std::string breed) {
        this->breed = breed;
        return *this;
    }

    Dog& set_age(int age) {
        *(this)->p_age = age;
        return *this;
    }
private:
    std::string name;
    std::string breed;
    int* p_age;
};
Dog::Dog(const std::string& _name, const std::string _breed, int _age){
    name = _name;
    breed = _breed;
    p_age = new int;
    *p_age = _age;
 
    std::cout << "Conctructor called for: " << name << " at address: " << this << std::endl;
}
Dog::~Dog(){
    delete p_age;
    std::cout << "Destructor called for: " << name << " at address: "<< this << std::endl;
}


int main() {  

    Dog dog1("Fluffy", "Shepherd", 6); // Constructor
    dog1.print();

   // dog1.set_name("Reksio");
   // dog1.set_breed("Beagle");
   // dog1.set_age(12);
    //dog1.set_name("Reksio")->set_breed("Beagle")->set_age(12);   // chained calls using pointers
    
    dog1.set_name("Reksio").set_breed("Beagle").set_age(12);// chained calls using references

    dog1.print();

    std::cout << "\nDone" <<std::endl;
    //Destructor
    return 0;
}

#include <iostream>

class Person{
public:
    // Person(const std::string& _full_name, int _age);

    Person(const std::string& _full_name, int _age)
        : full_name(_full_name), age(_age) {
            ++person_count;
        };

    void print_info() const{
        std::cout << "Name: " << full_name << " , age: " << age << std::endl;
    }
private:
    std::string full_name;
    int age;
public:
    static int person_count;

};

int Person::person_count = 8;

int main() {
    Person p1("John snow", 38);

    p1.print_info();

    return 0;
}

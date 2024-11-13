#include <cstring>
#include <cstdlib>

class Person {
public:
    Person(unsigned int _pesel, const char *_name, const char *_surname) {
        pesel = _pesel;
        name = strdup(_name);
        surname = strdup(_surname);
    }

    Person(const Person& copy) {
        pesel = copy.pesel;
        name = strdup(copy.name);
        surname = strdup(copy.surname);
    }

    Person& operator=(const Person& copy) {
        if (this != &copy) {
            free(name);
            free(surname);
            pesel = copy.pesel;
            name = strdup(copy.name);
            surname = strdup(copy.surname);
        }
        return *this;
    }

    ~Person() {
        free(name);
        free(surname);
    }

private:
    unsigned int pesel;
    char *name;
    char *surname;
};

int main() {
    Person p(1234567890, "Robert", "Kowalski");
    Person p2(p);
    Person p3(1234567890, "Adam", "Lewandowski");
    p = p3;
    return 0;
}
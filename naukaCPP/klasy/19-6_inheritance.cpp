#include <iostream>
#include <string>

class Person {
    //friend oznacza, że ta funkcja ma dostęp do prywatnych pól klasy Person, 
    // czyli w tym przypadku do first_name i last_name.

    //operator<< to przeciążenie operatora <<. Przeciążając go, możemy ustalić, 
    //jak obiekt Person powinien być wypisywany do strumienia wyjściowego (np. std::cout), 
    //czyli jak zostanie sformatowana informacja o nim podczas wywołania std::cout << person;
    friend std::ostream& operator<<(std::ostream& out, const Person& person) {
        out << "Person [" << person.first_name << " " << person.last_name << "]";
        return out;
    };

public:
    Person() = default;
    Person(const std::string& _first_name, const std::string& _last_name)
        : first_name(_first_name), last_name(_last_name) {};

    std::string get_first_name() const{
        return first_name;
    }
    std::string get_last_name() const{
        return last_name;
    }

private:
    std::string first_name = "Mysterious";
    std::string last_name = "Person";
};



class Player : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << "Player : [ game : " << player.m_game << " names : " <<
        player.get_first_name() << " " << player.get_last_name() << "]";
        return out;
    };
public:
    Player() = default;
    Player(const std::string& _game);

private:
    std::string m_game = "None";
};

int main() {  
    Player p1("Basketball");

    std::cout << p1 << std::endl;
    return 0;
}
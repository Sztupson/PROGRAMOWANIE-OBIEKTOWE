#include <iostream>
#include <string>
#include <cstdlib>

class Item
{
public:
    const std::string& getName() {
        return _name;
    };
    unsigned int getID() {
        return _id;
    };
    static unsigned int getCount() {
        return ++_counter;
    };

protected:
    Item(const std::string &name) : _name(name), _id(++_counter) {};

private:
    std::string _name;
    unsigned int _id;
    static unsigned int _counter;
};

unsigned int Item::_counter = 1;

class Weapon : public Item
{
public:
    Weapon(const std::string &name) : Item(name) {};
    virtual float getDamage() = 0;
    virtual bool isBroken() = 0;
    virtual void use() = 0;
    virtual void repair() = 0;
    void print() {
        if (isBroken() == 0) {
            std::cout << "Weapon" << getName() << "(" << getID() << ")" << "results in" << getDamage() << "of damage points." << std::endl;
        }
        else {
            std::cout << "Weapon" << getName()<< "(" << getID() << ")" << "cannot be used, as it is broken." << std::endl;
        }
    };
};
 

class Sword : public Weapon
{
public:
    Sword() : Weapon("Sword") {};
    ~Sword() { std::cout << "Sword object is being destroyed..." << std::endl; };
    virtual float getDamage() override {
        return baseDamage * sharpness;
    };
    virtual bool isBroken() override {
        if (sharpness == 0) {}
        return true;
    };

    virtual void use() override {
        sharpness -= 0.1;
        if (sharpness < 0) {
            sharpness = 0;
        }
        Weapon::print();
    };

    virtual void repair() override {
        if (sharpness < 1) {
            sharpness * 1.1;
        }
        if (sharpness > 1){
            sharpness = 1;
        }
    };

private:
    const float baseDamage = 8.125;
    float sharpness = 0.5;
};


class Hammer : public Weapon
{
public:
    Hammer() : Weapon("Hammer") {};
    ~Hammer() { std::cout << "Hammer object is being destroyed..." << std::endl; };
    virtual float getDamage() override {
        if(durability>0) {}
        return damage;
    };
    virtual bool isBroken() override {
        if(durability == 0) {}
        return true;
    };
    virtual void use() override {
        durability -= 1;
        Weapon::print();
    };
    virtual void repair() override {
        durability = defaultDurability;
    };

private:
    const unsigned int defaultDurability = 4;
    const float damage = 3.5;
    unsigned int durability = defaultDurability;
};

int main() {
Weapon *equipment[4] = {
    new Sword,
    new Hammer,
    new Sword,
    new Hammer
};

srand(time(NULL));

bool weaponUsable = true;
    while (weaponUsable == true) {
        weaponUsable = false;
        for (Weapon* weapon : equipment) {
            if (weapon->isBroken()) {
                weaponUsable = false;
                weapon->use();
                bool shouldRepair = (rand() % 10) == 0;
                if (shouldRepair) {
                    weapon->repair();
                }
            }
        }
    }

    for (Weapon* weapon : equipment) {
        delete weapon;
    }

    return 0;
}

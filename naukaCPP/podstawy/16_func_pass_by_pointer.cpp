#include <iostream>

void say_age(int age);
void ptr_say_age(int* age);


int main() {  
    int age = 20;
    //Przekazanie age bez pointera
    std::cout << "Age before function call: " << age << std::endl;
    say_age(age);
    std::cout << "Age after function call: " << age << std::endl;
    
    std::cout << "=====================" << std::endl;
    //Przekazanie age z pointerem
    std::cout << "Age before function call: " << age << std::endl;
    ptr_say_age(&age);  //PRZEKAZUJEMY ADRES!
    std::cout << "Age after function call: " << age << std::endl;

    return 0 ;
}


void say_age(int age) {
    ++age;
    std::cout << "You will be " << age << " years old next year." << std::endl;
}

void ptr_say_age(int* age) {
    ++(*age);
    std::cout << "You will be " << *age << " years old next year." << std::endl;
}
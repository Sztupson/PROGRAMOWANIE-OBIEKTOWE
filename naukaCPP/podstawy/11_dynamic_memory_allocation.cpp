#include <iostream>

int main() {  

    int *p_number {new int {44}}; // Writing into dynamic allocated memory

    std::cout << "Dynamically allocating memory" << 
    std::endl;
    
    std::cout << "p_number: " << *p_number << std::endl;
    
    delete p_number;
    
    std::cout << "Po 'delete' nie bedzie juz wartosci 44: " << *p_number << std::endl;

    p_number = new int(45);
    std::cout << p_number << std::endl;
    
    return 0;
}

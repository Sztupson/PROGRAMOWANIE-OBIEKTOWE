#include <iostream>

int main() {  
    std::cout << "Fill in your name and second name " << std::endl;
    std::string full_name;

    std::getline(std::cin, full_name); // Podaj imię i nazwisko oddzielone spacjami 
// dzięki temu rozwiązaniu unikamy błędu związanego z inputem oddzielonym spacjami
}
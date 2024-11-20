#include <iostream>

int main() {  
    int value = 50;
    double double_value = 30.31;

    int& ref{value};   //inicjalizowanie
    int& ref2 = value; //przypisywanie

    double& refdouble = double_value;

    std::cout << "Value: " << value << "\nReference value: " << ref << "\nSecond reference to same value: " << ref2 <<std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "Double value: " << double_value << "\nReference value: " << refdouble << std::endl;
    std::cout << "======================" << std::endl;

    ref = 10;

    std::cout << "Value: " << value << "\nReference value: " << ref << "\nSecond reference to same value: " << ref2 <<std::endl;

    std::cout << "======================" << std::endl;


    //PORÓWNANIE REFERENCJI I POINTERÓW:

    double double_data = 12.34;
    double& ref_double_data = double_data;
    double* ptr_double_data = &double_data;

    std::cout << "Double: " << double_data << std::endl;
    std::cout << "Double reference: " << ref_double_data << std::endl;
    std::cout << "Double pointer address: " << ptr_double_data << std::endl;
    std::cout << "Double pointer: " << *ptr_double_data << std::endl;
    std::cout << "======================" << std::endl;

    // zmiana wartości głownej zmiennej poprzez referencję

    ref_double_data = 15.61;

    std::cout << "Double: " << double_data << std::endl;
    std::cout << "Double reference: " << ref_double_data << std::endl;
    std::cout << "Double pointer address: " << ptr_double_data << std::endl;
    std::cout << "Double pointer: " << *ptr_double_data << std::endl;
    std::cout << "======================" << std::endl;

    // zmiana wartości głownej zmiennej przez pointera

    *ptr_double_data = 99.81;

    std::cout << "Double: " << double_data << std::endl;
    std::cout << "Double reference: " << ref_double_data << std::endl;
    std::cout << "Double pointer address: " << ptr_double_data << std::endl;
    std::cout << "Double pointer: " << *ptr_double_data << std::endl;

}
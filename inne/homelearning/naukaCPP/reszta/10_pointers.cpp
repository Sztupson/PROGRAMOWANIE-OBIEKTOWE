#include <iostream>

int main() {  
    //Declare and initialize pointer
    
    int* p_number {}; //Will initialize with nullptr
    double* p_fractional_number{};
    
    //Explicitly intitialize with nullptr
    int* p_number1{nullptr};
    int* p_fractional_number1{nullptr};
    
    //Pointers to different variables are of the same size:
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(double*): " << sizeof(double*) << std::endl;
    std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;
    std::cout << "sizeof(p_number1): " << sizeof(p_number1) << std::endl;
    std::cout << "sizeof(p_fractional_number1): " << sizeof(p_fractional_number1) << std::endl;
    
    //------------------
    
    int int_var {43};
    int* p_int{&int_var}; //The address of operator (&)
    
    std::cout << "Int var: " << int_var << std::endl;
    std::cout << "p_int (Adress in memory): " << p_int << std::endl;
    
    //You can change address stored in pointer at any time
    int int_var1 {65};
    p_int = &int_var1;
    std::cout << "p_int (with different address): " << p_int << std::endl;
    
    //Cant cross assign between pointers of different types
    int* p_int1{nullptr};
    double double_var{33};
    
    //p_int = &double_var; // compiler error
    
    
    
    //Dereferencing a pointer: 
    int* p_int2 {nullptr};
    int int_data {56};
    p_int2 = &int_data;
    
    std::cout << "Value: " << *p_int2 << std::endl; // Dereferencing a pointer
    
  


    int zmienna = 56;
    int* ptr;
    ptr = &zmienna;
    
    std::cout << *ptr << std::endl;
    
    return 0;
}

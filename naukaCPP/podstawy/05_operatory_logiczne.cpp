#include <iostream> 

int main() {  
    
    bool a {true};
    bool b {false};
    bool c {true};

    std::boolalpha;
    // || operator "or", && operator "i"
    std::cout << "a && b : " << (a && b) << std::endl;
    std::cout << "a && c : " << (a && c) << std::endl;
    std::cout << "a && b && c : " << (a && b && c) << std::endl;

    std::cout << "-------------------" << std::endl;

    std::cout << "a || b : " << (a || b) << std::endl;
    std::cout << "a || c : " << (a || c) << std::endl;
    std::cout << "a || b || c : " << (a || b || c) << std::endl;

    std::cout << "-------------------" << std::endl;

    std::cout << "!a: " << !a << "   !b: " << !b << "   !c: " << !c << std::endl;

    std::cout << "-------------------\n Combining operators: " << std::endl;

    std::cout << "!(a && b) || c    ====>   " << (!(a && b) || c) << std::endl;

}  
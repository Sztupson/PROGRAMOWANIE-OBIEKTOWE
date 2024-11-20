 #include <iostream>

int main() {  
    
    int max{};

    int a{200};
    int b{1};

    std::cout << std::endl;
    std::cout << "Using regular if: " << std::endl;

    if (a > b) {
        max = a;
    }else{
        max = b;
    }

    std::cout << "max: " << max << std::endl;

    std::cout << "-------------" << std::endl;
    std::cout << "Using short hand if else" << std::endl;

    max =  (a > b) ? a : b;
    std::cout << "max: " << max << std::endl;

    return 0;
}
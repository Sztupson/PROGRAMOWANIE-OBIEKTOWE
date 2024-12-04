#include <iostream>

int sum(int a , int b) {
    int result = a + b;
    std::cout << "&result(int)  " << &result << std::endl;
    return result;
}


int main() {  

    int a = 35;
    int b = 50;

    int result = sum(a, b);
    std::cout << "Out : &result(int)  " << &result << std::endl; // kopia
    std::cout << "Sum : " << result << std::endl;

    return 0;
}
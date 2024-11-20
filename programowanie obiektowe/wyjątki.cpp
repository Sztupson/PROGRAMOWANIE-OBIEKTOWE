#include <iostream>
#include <stdexcept>

double mydiv(int a, int b){
    if (b==0) {throw std::invalid_argument("BOOM\n");}
    return a/(double)b;
}

int main() {
    
    try
    {
        mydiv(5,0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "BLAD\n";
    }
    std::cout << "Kontynuacja programu\n";
    // new int[1000000000000000000000000000000000];
    return 0;
}
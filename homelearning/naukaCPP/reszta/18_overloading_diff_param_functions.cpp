#include <iostream>

int max(int a, int b) {
    std::cout << "Int overloaded" << std::endl;
    return (a>b) ? a : b;
}
/*Cannot overload on the return type. Compiler error 

diff return //int  //int
double max(int a, int b) {
    return (a>b) ? a : b;
}
*/

double max (double a, double b) {
    std::cout << "Double overloaded" << std::endl;
    return (a>b) ? a : b;
} 

double max (int a, double b) {
    std::cout << "1.Int 2.Double overloaded" << std::endl;
    return (a>b) ? a : b;
}

double max (double a, int b, int c) {
    std::cout << "1.Double 2.Int 3.Int overloaded" << std::endl;
    return (a>b) ? a : b;
}


std::string_view max (std::string_view a, std::string_view b) {
    std::cout << "String_view overloaded" << std::endl;
    return (a>b) ? a : b;
}


int main() {  
    int x = 4;
    int y = 9;
    double a = 5.4;
    double b = 7.4;

    auto result = max(a,b);
    auto result1 = max(x,y);
    auto result2 = max(a,x,y);
    auto result3 = max(x,a);
    max("Hello", "World");
//Kompiler wybierze sam, która funkcja będzie najlepiej pasować do określonych argumentów.
}
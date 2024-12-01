#include <iostream>

//Function declaration
int max(int a, int b);
// Mozna tez zapisac: int max(int , int );


int main() {  
    int number = 3;
    int second_number = 4;

    std::cout << "Max 3 and 4: " << max(number, second_number) << std::endl;

}

int max (int a, int b) {
    int max = a > b ?  a :  b;
    return max;
}
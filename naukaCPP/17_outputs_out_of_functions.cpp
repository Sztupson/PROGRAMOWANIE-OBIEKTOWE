#include <iostream>
#include <string>

void max_str(const std::string& input1, const std::string& input2, std::string& output) {
    if(input1 > input2){
        output = input1;
    }else{
        output = input2;
    }
};

void max_int(int input1, int input2, int& result){
    result = (input1 > input2) ? input1 : input2;
}

void max_double(double input1, double input2, double* result) {
    if(input1 > input2) {
        *result = input1;
    } else {
        *result = input2;
    }
}

int main() {  

    std::string output;
    std::string string1 = "Polska";
    std::string string2 = "Gurom";
    max_str(string1, string2, output);

    std::cout << output << std::endl;


    int first_number = 90;
    int second_number = 102;
    int result{};
    max_int(first_number, second_number, result);

    std::cout << result << std::endl;


    double d1 = 90.11;
    double d2 = 90.24;
    double value{};
    max_double(d1,d2,&value);

    std::cout << value << std::endl;

    return 0;
}
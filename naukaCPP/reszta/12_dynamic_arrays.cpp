#include <iostream>

int main() {  
    size_t size{10};
    double* p_salaries {new(std::nothrow) double [size]{1,2,3,4,5}}; // 5 wartosci podanych, reszta wypełni się 0, a nie losowymi liczbami
    for (size_t i = 0; i < size; i++){
        std::cout << "["<< i << "]Value: " << p_salaries[i] << " : " << *(p_salaries + i) << std::endl;
    }
    delete[] p_salaries; // należy pamiętać o [] w celu usuniecia calej tablicy
}
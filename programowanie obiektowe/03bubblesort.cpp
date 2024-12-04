#include <iostream>
#include <algorithm>
#include <array>

template <typename T, size_t n>
void bubble_sort(std::array<T,n>& array) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++){ 
            if(array[j] > array[j+1]) {
                std::swap(array[j], array[j+1]);
            }
        }
    }
}
// std::swap
int main() {
    const size_t n = 5;
    std::array<int,n> array = {5,4,3,6,1};



    bubble_sort(array);
    for(int i = 0; i < n; i++) {std::cout << array[i] << std::endl;}
    
   
}
#include <iostream>

// template <typename T> T myMax(T x, T y) {return (x>y) ? x : y;}

// int main() {
//     std::cout << myMax<int>(2,5) << "\n";
//     std::cout << myMax<double>(2.23, 2.42) << "\n";
//     std::cout << myMax<char>('g', 'e') << "\n";

//     return 0;
// }


template<class T> void bubble_sort(T a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
            }
        }
    }
} 

int main()  {
    int a[5] = {30, 45, 11, 28, 59};
    int n = sizeof(a) / sizeof(a[0]);

    bubble_sort<int>(a,n);

    std::cout << "Sorted array: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }

}
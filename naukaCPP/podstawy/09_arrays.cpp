#include <iostream>

int main() {  

int class_sizes[] {6,5,3,32};

for(auto value : class_sizes) {
    std::cout << "value: " << value << std::endl;
}

/* auto value : class_sizes

Dwukropek oznacza w tym kodzie pętlę zakresową, która pozwala 
przeiterować przez wszystkie elementy tablicy bez potrzeby
używania indeksowania do przejścia po wszystkich elementach:

for(int i = 0; i < 5; i++) {
    std::cout << "value: " << class_sizes[i] << std::endl;
}

*/

//SIZE OF ARRAY:

std::cout << "class_sizes size: " << std::size(class_sizes) << std::endl;
//std::size - odpowiednik len() w pythonie

std::cout << "-------------------------- "<< std::endl;
std::cout << "sizeof(class_sizes) " << sizeof(class_sizes) << std::endl;
std::cout << "sizeof(class_sizes[0]) " << sizeof(class_sizes[0]) << std::endl;

int count {sizeof(class_sizes)/sizeof(class_sizes[0])};
for(size_t i = 0; i < count; i++){
    std::cout << "class_sizes [" << i << "] : " << class_sizes[i] << std::endl;
}

}
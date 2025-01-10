 #include <iostream>

int main() {  

const size_t COUNT = 3;
size_t i = 0;



std::cout << "--------------" << std::endl;
for(i = 0; i < COUNT; i++){
    std::cout << "I love cpp" << std::endl;
}
std::cout << "--------------" << std::endl;


i = 0;


while (i < COUNT) {
    std::cout << "I hate cpp" << std::endl;
    ++i;
}
std::cout << "--------------" << std::endl;

i = 0;

do{
    std::cout << "[" << i << "] " << "I LOVE CPP" << std::endl;
    i++;
} while (i < COUNT);
// DO WHILE first runs the body then checks while (i < COUNT);
std::cout << "--------------" << std::endl;



}
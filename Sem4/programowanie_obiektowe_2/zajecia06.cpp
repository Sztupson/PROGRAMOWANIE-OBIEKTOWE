

// # def something():
// #     ff = Foo("Krzysio")

// # class Foo:
// #     def __init__(self, name):
// #         self.name = name
// #         print(f"Foo({self.name}):__init__")
// #     def __del__(self):
// #         print(f"Foo({self.name}):__del__")

// # f = Foo("Aston")
// # g = Foo("Lukas")

// # del f

// # x = input("Wpisz coś: ")

// # something()

// # y = []
// # print(y[0])
// # print("jestem tutaj")
#include <iostream>

class Foo {
public:
    int x_;

    Foo(int x): x_(x){
        std::cout << "Foo" << std::endl;
    }

    ~Foo() {
        std::cout << "~Foo" << std::endl;
    }
};

int main(){
    
    Foo f = Foo(123);

    int x = 2, y = 0;

    std::cout << (x/y) << std::endl;

    return 0;
}
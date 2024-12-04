#include <iostream>
#include <vector>
#include <string>

// class RozneRzeczy {
// public:
//     int liczba = 154;
//     std::string samochod = "bmw";
//     char znak = 'b';
// };

int main() {
    /*


    std::vector<std::string> samochody = {"bmw", "mazda", "toyota", "renault", "volkswagen"};
    //std::vector<RozneRzeczy> tasks;
    std::cout << samochody[1] << std::endl;
    std::cout << samochody.front() << std::endl; // wyswietlanie pierwszego elementu
    std::cout << samochody.back() << std::endl; // wyswietlanie ostatniego elementu
    std::cout << samochody.at(1) << std::endl; // drugi element
    std::cout << samochody.at(2) << std::endl; // trzeci element
                                               // .at() czesciej uzywane niz example[x]
                                               // bo daje znac jezeli bedzie error
    //std::cout << samochody.at(6) << std::endl; //terminate called after throwing an instance of 'std::out_of_range'
                                               // what():  vector::_M_range_check: __n (which is 6) >= this->size() (which is 5)
    //samochody[0] = "opel";
    //zamienianie elementów
    samochody.at(0) = "opel";
    std::cout << samochody.at(0) << "\n===========" << std::endl;

    //dodawanie elementów na końcu
    samochody.push_back("tesla");
    std::cout<< samochody.at(5) << std::endl;


    //usuwanie elementów
    samochody.pop_back();
    //std::cout<< samochody.at(5) << std::endl; // blad

    //rozmiar tablicy
    std::cout << samochody.size() << std::endl;

    //sprawdzanie czy vector jest pusty:
    std::vector<std::string> cars;
    std::cout << cars.empty() << std::endl;// 1- vector empty
    cars.push_back("mitsubishi");
    std::cout << cars.empty() << std::endl;// 0 - vector not empty


    */



    //
    // for loop
    //

    std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    for (std::string car : cars) {
        std::cout << car << "\n";
    }


    return 0;
}
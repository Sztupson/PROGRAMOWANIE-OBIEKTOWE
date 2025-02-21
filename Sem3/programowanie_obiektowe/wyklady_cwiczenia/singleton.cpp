#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
/*
prywatny konstruktor,
metoda tworząca lub zwracająca już istniejącą instancję,
brak konstruktora kopiującego,
brak operatora przypisania.
*/



class Singleton {
public:
    ~Singleton() { saveFile(); }

    static Singleton& getInstance() { 
        static Singleton instance; 
        return instance; 
    }

    void set(const std::string &key, const std::string &value) { str_str[key] = value; }
    void set(const std::string &key, const int value) { str_int[key] = value; }

    std::string getString(const std::string &key) { 
        std::cout << "Metoda getstring: "<< str_str[key] << std::endl;
        return str_str[key]; 
    }
    int getInt(const std::string &key) { 
        std::cout << "Metoda getInt: "<< str_int[key] << std::endl;
        return str_int[key]; 
    }

private:
    Singleton() { loadFile(); }


    std::unordered_map<std::string, std::string> str_str;
    std::unordered_map<std::string, int> str_int;
    void loadFile() {
        std::ifstream stringFile("stringi.txt");
        std::string key, value;
        int intValue;

        while (std::getline(stringFile, key) && std::getline(stringFile, value)) {
            str_str[key] = value;
        }

        std::ifstream intFile("string_int.txt");
        while (std::getline(intFile, key) && intFile >> intValue) {
            str_int[key] = intValue;
        }
    }

    void saveFile() const {
        std::ofstream stringFile("stringi.txt");
        for (const auto& pair : str_str) {
            stringFile << pair.first << '\n' << pair.second << '\n';
        }

        std::ofstream intFile("string_int.txt");
        for (const auto& pair : str_int) {
            intFile << pair.first << '\n' << pair.second << '\n';
        }
    }
};



int main() {
    Singleton &singleton = Singleton::getInstance();


    std::cout << singleton.getInt("dwa") << std::endl;
    singleton.getString("siema");



    singleton.set("lukasz", "k");
    singleton.set("dziewiec", 9);


    return 0;
}
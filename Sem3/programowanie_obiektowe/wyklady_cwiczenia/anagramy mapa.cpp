#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {return false;}
    std::unordered_map<char, int> frequencyMap1;
    std::unordered_map<char, int> frequencyMap2;
    for (char c : str1) {
        char lowerChar = std::tolower(c); 
        frequencyMap1[lowerChar]++;
    }
    for (char c : str2) {
        char lowerChar = std::tolower(c); 
        frequencyMap2[lowerChar]++;
    }
    return frequencyMap1 == frequencyMap2;
}

int main() {
    std::string str1, str2;
    std::cout << "Podaj pierwszy ciąg znaków: ";
    std::getline(std::cin, str1);

    std::cout << "Podaj drugi ciąg znaków: ";
    std::getline(std::cin, str2);

    if (areAnagrams(str1, str2)) {
        std::cout << "Ciągi są anagramami.\n";
    } else {
        std::cout << "Ciągi nie są anagramami.\n";
    }

    return 0;
}

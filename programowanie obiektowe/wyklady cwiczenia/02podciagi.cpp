#include <iostream>
#include <string>
#include <set>


std::set<std::string> generateSubstrings(const std::string& string) {
    std::set<std::string> substrings; 
    for (int i = 0; i < string.size(); i++) {
        std::string substring;
        for (size_t j = i; j < string.size(); j++) {
            substring += string[j]; 
            substrings.insert(substring); 
        }
    }
    return substrings;
}

int main() {
    std::string word = "alfabet";

    std::set<std::string> substrings = generateSubstrings(word);

    std::cout << "Unikalne podciągi:\n";
    for (const auto& s : substrings) {std::cout << s << "\n";}

    return 0;
}
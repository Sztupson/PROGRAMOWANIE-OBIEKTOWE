#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool anagrams(std::string word1, std::string word2) {

    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    if(word1.length() != word2.length()) {return false;}
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    return word1 == word2;
}

int main() {
    std::string w1 = "log";
    std::string w2 = "gol";
    bool anag = anagrams(w1,w2);

    if (anag) {
        std::cout << "Podana para wyrazów to anagramy";
        } else {
        std::cout << "Podana para wyrazów to nie są anagramy";
        }
    return 0;

}
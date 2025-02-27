#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class YourSorter {
protected:
    const std::vector<T> &vec;
public:
    YourSorter(const std::vector<T>& v) : vec(v) { std::cout << "Wywolanie konstruktora.\n\n"; };
    virtual void sort(bool descending = false) = 0;
    virtual ~YourSorter() { std::cout << "Wirtualny destruktor."; }
};

template <typename T>
class BubbleSort : public YourSorter<T> {  // ZLOZONOSC O(n^2)
private:
    std::vector<T> vec2; // drugi vector do skopiowania pierwszego vectora ktory jest const jak w poleceniu
public: 
    BubbleSort(const std::vector<T>& v) : YourSorter<T>(v), vec2(v) {}
    void sort(bool descending = false) override {
        for(size_t i = 0; i < vec2.size(); ++i) {
        for(size_t j = 0; j < vec2.size() - i - 1; ++j){ 

                if((descending && vec2[j] < vec2[j+1]) || (!descending && vec2[j] > vec2[j+1])) {
                    std::swap(vec2[j], vec2[j+1]);
                }
                
        }
        }
    for(const auto& val : vec2) {
        std::cout << val << " ";
    }
    }
};

int main() {
    std::vector<double> v{5.2, -5.1, 6, 10.001, 1111};
    auto s = BubbleSort(v);

    std::cout << "Posortowano malejaco: \n";
    s.sort(true);
    std::cout << "\n\n";


    std::cout << "Posortowano rosnaco: \n";
    s.sort(false);
    std::cout << "\n\n";
    
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstring>

class TimeLenght {
public:
    TimeLenght(const char *_seconds) {
        copy = strdup(_seconds);
        unsigned long int allSeconds = strtoul(_seconds, NULL, 10);

        seconds = allSeconds % 60;
        minutes = (allSeconds % 3600) / 60;
        hours = allSeconds / 3600;
    }; // konstruktor
    ~TimeLenght() {free(copy);}; // destruktor

    TimeLenght(const TimeLenght& other) {
        copy = strdup(other.copy);
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }; // konstruktor kopiujący

    const char* getString() const {return copy;};
    static TimeLenght createZeroLenght(){return TimeLenght("0");};

    friend std::ostream& operator<<(std::ostream &out, const TimeLenght &time) {
        out << time.hours << "h " << time.minutes 
        << "min " << time.seconds << "sec\n";
        return out;
    }
private:
    char *copy;
    unsigned long hours;
    unsigned long minutes;
    unsigned long seconds;
};


int main() {  
    //Efekt: 5h, 26min, 32sec
    TimeLenght uptime("19592");
    std::cout << uptime << std::endl;
    // zwracanie kopii
    std::cout << uptime.getString() << std::endl;
    
     
    std::cout << "Uptime po użyciu funkcji createZeroLenght: " << uptime.createZeroLenght() << std::endl;
    return 0;
}
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

class IfPrime
{
public:
    IfPrime(unsigned int threads)
    {
        this->threads = threads;
        this->isPrime = isPrime;
    }

    bool check(unsigned int n) {
        /* Uruchamiamy wątki */
        std::vector<std::thread> threads;

        for (int i = 0; i < this->threads; i++)
        {
            if (n == 1) return false;
            if (n == 2) return true;

            const unsigned int limit = sqrt(n);
            unsigned int range = limit / this->threads;

            unsigned int from = i * range;
            unsigned int to = (i + 1) * range;
            std::cout << from << " " << to << std::endl;
            threads.push_back(std::thread(&IfPrime::threadFunction, this, from, to));
        }
        for (int i = 0; i < this->threads; i++)
        {
            threads[i].join();
        }

        return false;
    }

private:
    void threadFunction(unsigned int from, unsigned int to) {
        /*
        
        for (unsigned int i = 2; i <= limit; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
        */
    }
    volatile bool isPrime;
    unsigned int threads;
};

int main() {
    unsigned int hwThreads = std::thread::hardware_concurrency();
    hwThreads = hwThreads ? hwThreads : 1;
    IfPrime p(hwThreads);

    unsigned int n = 1000;
    if (p.check(n))  {
        std::cout << "Liczba " << n << " jest pierwsza" << std::endl;
    } else {
        std::cout << "Liczba " << n << " nie jest pierwsza" << std::endl;
    }

    return 0;
}
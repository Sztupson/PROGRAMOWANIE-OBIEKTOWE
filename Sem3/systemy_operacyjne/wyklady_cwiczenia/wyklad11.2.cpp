#include <thread>
#include <iostream>
#include <string>
#include <unistd.h>
#include <condition_variable>
#include <mutex>


std::mutex mutex;
std::condition_variable cv;
std::string sharedString;
bool flag = false;



void threadFunc() {
    std::cout << "watek oczekuje na zmiane flagi\n";

    {
        std::unique_lock lock(mutex); /* automatyczny lock() ma muteksie */
        cv.wait(lock, []{ return flag; });

        /* Kontynuujemy wykonanie, gdy flaga zostanie zmieniona na true */
        std::cout <<  "watek zaczyna dzialanie\n";
        std::cout << sharedString << std::endl;
        sharedString = "zmiana w thread";
        /* mutex unlock w destruktorze unique_lock */
    }

    while(!flag);
    sleep(3);

    std::cout << "Watek zaczyna dzialanie\n";
    std::cout << sharedString << std::endl;
    sharedString = "kot ma ale";

    flag = false;
}

int main() {
    std::thread t(threadFunc);
    sleep(3);

    {
        std::lock_guard lock(mutex); /* mutex lock */
        sharedString = "zmiana w main()";
        flag = true;
        cv.notify_one();
        /* mutex unlock w destruktorze lock_guard */
    }


    sharedString = "ala ma kota";
    std::cout << "main zmienia flage\n";
    flag = true;

    while(flag);
    std::cout << sharedString << std::endl;


    t.join();
    return 0;
}
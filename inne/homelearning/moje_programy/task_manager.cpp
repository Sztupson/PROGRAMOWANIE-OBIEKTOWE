#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Task {
public:
    unsigned int id = 0;
    std::string name;
    std::string desc;
    unsigned int priority; //zakres 0-9  
    bool completion;
};

class TaskManager{
private:
    std::vector<Task> tasks; 
    unsigned int nextId = 1;
public:
    TaskManager() = default;

    void addTask(const std::string& name, const std::string& desc, unsigned int priority) {
        tasks.push_back({nextId, name, desc, priority, false});
        std::cout << "Dodano nowe zadanie: " << name << " o numerze id: " << nextId << std::endl;
        nextId++;
    }


    void showTasks(){
<<<<<<< HEAD:moje programy/task_manager.cpp
        tasks.empty() && std::cout << "Brak zadan do wyswietlenia\n"; //"short hand if"

=======
        if(tasks.empty()) {std::cout << "Brak zadan do wyswietlenia.\n";}
>>>>>>> c6e8263736602273e0ed1b0e749dc058a930668c:homelearning/moje programy/task_manager.cpp
        for (auto task : tasks) {
            std::cout << "[" << task.id << "] " << task.name << ":\n"
                      << task.desc << "\n" << "(Priorytet: " << task.priority
                      << ", Ukonczono: " << (task.completion ? "Tak" : "Nie") << ")\n";
        }
    }
    // void showTasks(unsigned int id){
    //     if(id > 0 && id <= tasks.size()){
    //         std::cout << "[" << tasks.at(id).id << "] " << tasks.at(id).name << ":\n"
    //                   << tasks.at(id).desc << "\n" << "(Priorytet: " << tasks.at(id).priority
    //                   << ", Ukonczono: " << (tasks.at(id).completion ? "Tak" : "Nie") << ")\n";
    //     } else { std::cout << "Niepoprawna wartosc ID.\n"; }
    // }   


    void removeTask(unsigned int id2){
        if(id2<1 || id2 > tasks.size()) {std::cout << "Brak zadania o numerze ID: " << id2 << std::endl;}
        for(auto task : tasks) {
            if(task.id == id2){
                tasks.erase(tasks.begin() + id2-1);
                std::cout << "Usunieto zadanie: " << task.name << "\n";
            }
        }


        // if(id2 > 0 && id2 <= tasks.size()){
        //     tasks.erase(tasks.begin() + (id2-1));
        // } else { std::cout << "Niepoprawna wartosc ID.\n"; }
    }
    void taskCompletedMark(unsigned int id2){
        for(auto task : tasks) {
            if(task.id == id2) {
                task.completion = true;
                std::cout << "Ukonczono zadanie: " << task.name << ", o numerze id: " << task.id << std::endl;
            } else {
                std::cout << "Brak zadania o numerze ID: " << id2 << std::endl;
            }
        }  
    }
};

void displayMenu() {
        std::cout << "\nZarzadzanie zadaniami:\n"
                  << "1. Dodaj zadanie\n"
                  << "2. Wyswietl dostepne zadania\n"
                  << "3. Oznacz jako ukonczone\n"
                  << "4. Usun zadanie\n"
                  << "5. Wyjscie\n"
                  << "Wybierz opcje: ";
}

int main() {
    TaskManager manager;
    int choice = 0;
    
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            std::string name;
            std::string desc;
            int priority;


            std::cout << "Podaj nazwe zadania: ";
<<<<<<< HEAD:moje programy/task_manager.cpp
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Czyszczenie bufora wejściowego
=======
            //std::cin >> name;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
>>>>>>> c6e8263736602273e0ed1b0e749dc058a930668c:homelearning/moje programy/task_manager.cpp
            std::getline(std::cin, name);

            std::cout << "Podaj opis zadania: ";

            std::getline(std::cin, desc);
            

            while (true) {
            std::cout << "Podaj priorytet (0-3): ";
            std::cin >> priority;
            if (std::cin.fail() || priority < 0 || priority > 3) {
                std::cin.clear(); // Resetuje flagę błędu
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Czyści bufor wejściowy
                std::cout << "Nieprawidlowy priorytet. Wprowadz liczbe miedzy 0 a 3." << std::endl;
                } else {break;}
            }
            manager.addTask(name, desc, priority);
            break;
        }
        case 2:{
            manager.showTasks();
            // unsigned int id;
            // std::cout << "Wyswietl wszystkie zadania[wpisz 0],\nwyswietl konkretne zadanie - podaj ID zadania: ";
            // std::cin >> id;
            // manager.showTasks(id);
            break;
        }
        case 3: {
            unsigned int id;
            std::cout << "Podaj ID zadania, ktore ukonczono: ";
            std::cin >> id;
            manager.taskCompletedMark(id);
            break;
        }
        case 4: {
            unsigned int id;
            std::cout << "Podaj ID zadania do usuniecia: ";
            std::cin >> id;
            manager.removeTask(id);
            break;
        }
        case 5:
            std::cout << "Koniec programu" << std::endl;
            break;
        
        default:
            std::cout << "Nieprawidlowy numer, sprobuj ponownie.\n";
        }
    } while (choice!=5);
    return 0;
}
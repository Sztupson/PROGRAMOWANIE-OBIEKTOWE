#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Task {
    int id;
    std::string name;
    std::string priority;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& name, const std::string& priority) {
        tasks.push_back({nextId++, name, priority, false});
        std::cout << "Dodano zadanie: " << name << "\n";
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "Brak zadań na liście.\n";
            return;
        }

        std::cout << "Lista zadań:\n";
        for (const auto& task : tasks) {
            std::cout << "[" << task.id << "] " << task.name
                      << " (Priorytet: " << task.priority
                      << ", Ukończone: " << (task.completed ? "Tak" : "Nie") << ")\n";
        }
    }

    void markTaskCompleted(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                std::cout << "Zadanie oznaczone jako ukończone: " << task.name << "\n";
                return;
            }
        }
        std::cout << "Nie znaleziono zadania o ID: " << id << "\n";
    }

    void removeTask(int id) {
        auto it = std::remove_if(tasks.begin(), tasks.end(),
                                 [id](const Task& task) { return task.id == id; });

        if (it != tasks.end()) {
            std::cout << "Usunięto zadanie o ID: " << id << "\n";
            tasks.erase(it, tasks.end());
        } else {
            std::cout << "Nie znaleziono zadania o ID: " << id << "\n";
        }
    }
};

void displayMenu() {
    std::cout << "\n=== System Zarządzania Zadaniami ===\n"
              << "1. Dodaj zadanie\n"
              << "2. Wyświetl zadania\n"
              << "3. Oznacz zadanie jako ukończone\n"
              << "4. Usuń zadanie\n"
              << "5. Wyjście\n"
              << "Wybierz opcję: ";
}

int main() {
    TaskManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string name, priority;
                std::cout << "Podaj nazwę zadania: ";
                std::getline(std::cin, name);
                std::cout << "Podaj priorytet zadania (niski/średni/wysoki): ";
                std::getline(std::cin, priority);
                manager.addTask(name, priority);
                break;
            }
            case 2:
                manager.displayTasks();
                break;
            case 3: {
                int id;
                std::cout << "Podaj ID zadania do oznaczenia jako ukończone: ";
                std::cin >> id;
                manager.markTaskCompleted(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Podaj ID zadania do usunięcia: ";
                std::cin >> id;
                manager.removeTask(id);
                break;
            }
            case 5:
                std::cout << "Koniec programu. Do widzenia!\n";
                break;
            default:
                std::cout << "Nieprawidłowa opcja, spróbuj ponownie.\n";
        }
    } while (choice != 5);

    return 0;
}

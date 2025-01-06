#include <iostream>
#include <string>

class InputHandler {
public:
    void printMenu() {
        std::cout << "Menu Options:\n";
        std::cout << "1. Select code file\n";
        std::cout << "2. Execute test\n";
        std::cout << "3. Exit\n";
    }

    void printExecuteTestMenu() {
            std::cout << "Execute Test Menu:\n";
            std::cout << "1. Successful Execution\n";
            std::cout << "2. Choose Test Output\n";
            std::cout << "3. Back to Main Menu\n";
    }

    int getUserInput() {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }
};
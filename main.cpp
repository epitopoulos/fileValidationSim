#include <iostream>
#include <string>
#include "InputHandler.h"
#include "FlashModule.h"
#include "TestModule.h"
#include "ReportingModule.h"

int main() {
    InputHandler inputHandler;
    FlashModule flashModule;
    TestModule testModule;
    ReportingModule reportingModule;

    while (true) {
        inputHandler.printMenu();
        int choice = inputHandler.getUserInput();

        if (choice == 1) {
            std::string testFilename;
            std::cout << "Enter the code filename to flash (e.g., test1.py): ";
            std::cin >> testFilename;
            flashModule.setExecFilename(testFilename);

        } else if (choice == 2) {
            std::string testFilename = flashModule.getExecFilename();
            if (testFilename.empty()) {
                std::cout << "No code file selected. Please select a file first.\n";
            } else {
                inputHandler.printExecuteTestMenu();
                int testChoice = inputHandler.getUserInput();

                if (testChoice == 1) {
                    bool result = testModule.runTest(testFilename);
                    reportingModule.reportResult(result);
                } else if (testChoice == 2) {
                    std::string desiredOutputFilename;
                    std::string testOutputFilename;

                    std::cout << "Enter the file that you want to compare the output to: ";
                    std::cin >> desiredOutputFilename;

                    std::cout << "Enter the file that will contain the test output: ";
                    std::cin >> testOutputFilename;
                    
                    testModule.compareFiles(desiredOutputFilename, testOutputFilename, testFilename);
                } else if (testChoice == 3) {
                    continue;
                } else {
                    std::cout << "Invalid choice, please try again.\n";
                }
            }

        } else if (choice == 3) {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
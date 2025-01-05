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
            std::string filename;
            std::cout << "Enter the code filename to flash (e.g., test1.py): ";
            std::cin >> filename;
            flashModule.setExecFilename(filename);
            std::cout << "Code file " << filename << " flashed successfully.\n";

        } else if (choice == 2) {
            std::string filename = flashModule.getExecFilename();
            if (filename.empty()) {
                std::cout << "No code file selected. Please select a file first.\n";
            } else {
                testModule.runTest(filename);
                // Optionally compare outputs and use reporting module here
                bool result = testModule.compareFiles("test_output.txt", "out1.txt");
                std::cout << result;
                reportingModule.reportResult(result);

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
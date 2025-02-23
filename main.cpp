#include <iostream>
#include <string>
#include "InputHandler.h"
#include "FlashModule.h"
#include "TestModule.h"
#include "ReportingModule.h"

int main(int argc, char *argv[]) {
    InputHandler inputHandler;
    FlashModule flashModule;
    TestModule testModule;
    ReportingModule reportingModule;
    
    std::string command = argv[1];
    if (command == "flashCode") {
        std::string filename = argv[2];
        flashModule.setExecFilename(filename);
    }

    if (command == "runTest") {
        std::string filename = flashModule.getExecFilename();
        std::cout << "Running test on file: " << filename << std::endl;
        bool result = testModule.runTest(filename);
        reportingModule.reportResult(result);
    }

    if (command == "compareFiles") {
        std::string desiredOutputFilePath = argv[2];
        std::string testOutputFilePath = argv[3];
        std::string pythonScriptFilePath = flashModule.getExecFilename();
        testModule.compareFiles(desiredOutputFilePath, testOutputFilePath, pythonScriptFilePath);
    }

    /*

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
    */
    return 0;
}
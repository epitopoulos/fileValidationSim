#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

class TestModule {
public:
    //Simple test to check if the script runs successfully
    bool runTest(const std::string& filename) {
        std::string command = "python " + filename;
        int result = system(command.c_str());
        return result;
    }

    // Helper function to trim whitespace from the beginning and end of a string
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, last - first + 1);
    }

void compareFiles(const std::string& desiredOutputFilePath, const std::string& testOutputFilePath, const std::string& pythonScriptFilePath) {
    // Run the Python script and redirect its output to testOutputFilePath
    std::string command = "python " + pythonScriptFilePath + " > " + testOutputFilePath;
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error: Failed to execute the Python script." << std::endl;
        return;
    }

    std::ifstream desiredFile(desiredOutputFilePath);
    std::ifstream testFile(testOutputFilePath);

    // Check if either file failed to open
    if (!desiredFile.is_open() || !testFile.is_open()) {
        std::cerr << "Error: One or both files could not be opened." << std::endl;
        return;
    }

    std::string desiredLine, testLine;
    bool areSame = true;

    // Skip the first line of the test output file
    std::getline(testFile, testLine);

    // Compare the files line by line
    while (std::getline(desiredFile, desiredLine)) {
        // Get the corresponding line from the test output file
        if (!std::getline(testFile, testLine)) {
            // If we can't read from the test file but desiredFile has more lines, they don't match
            areSame = false;
            std::cout << "Files do not match at line: " << desiredLine << std::endl;
            break;
        }

        // Trim whitespace and ignore line-ending differences
        desiredLine = trim(desiredLine);
        testLine = trim(testLine);

        if (desiredLine != testLine) {
            areSame = false;
            std::cout << "Files do not match at line: " << desiredLine << std::endl;
            break;
        }
    }

    // Skip the last line of the test output file
    std::getline(testFile, testLine);

    // Check if testFile has more lines
        while (std::getline(testFile, testLine)) {
            // If testFile has non-empty lines after desiredFile ends, they don't match
            if (trim(testLine) != "") {
                areSame = false;
                std::cout << "Files do not match. Extra line in test file: " << testLine << std::endl;
                break;
            }
        }

    if (areSame) {
        std::cout << "Files match!" << std::endl;
    }
}
};
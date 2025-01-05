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
        
        // Run the Python script and redirect its output to file2Path
        std::string command = "python3 " + pythonScriptFilePath + " > " + testOutputFilePath;
        int result = system(command.c_str());
        if (result != 0) {
            std::cerr << "Error: Failed to execute the Python script." << std::endl;
            return;
        }
        
        std::ifstream file1(desiredOutputFilePath);
        std::ifstream file2(testOutputFilePath);

        // Check if either file failed to open
        if (!file1.is_open() || !file2.is_open()) {
            std::cerr << "Error: One or both files could not be opened." << std::endl;
            return;
        }

        std::string line1, line2;
        bool areSame = true;

        // Compare the files line by line
        while (std::getline(file1, line1)) {

            // Skip specific lines
            if (line1 == "Starting to generate sequences of numbers..." || line1 == "Done!")
                continue;

            // Get the corresponding line from the second file
            if (!std::getline(file2, line2)) {
                // If we can't read from the second file but file1 has more lines, they don't match
                areSame = false;
                std::cout << "Files do not match at line: " << line1 << std::endl;
                break;
            }

            // Trim whitespace and ignore line-ending differences
            line1 = trim(line1);
            line2 = trim(line2);

            if (line1 != line2) {
                areSame = false;
                std::cout << "Files do not match at line: " << line1 << std::endl;
                break;
            }
        }

        // Check if file2 has more lines
        if (areSame) {
            while (std::getline(file2, line2)) {
                // If file2 has non-empty lines after file1 ends, they don't match
                if (trim(line2) != "") {
                    areSame = false;
                    std::cout << "Files do not match. Extra line in file2: " << line2 << std::endl;
                    break;
                }
            }
        }

        if (areSame) {
            std::cout << "Files match!" << std::endl;
        } else {
            std::cout << "Files do not match." << std::endl;
        }

        return;
    }
};
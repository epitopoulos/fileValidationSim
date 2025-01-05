#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

class TestModule {
public:
    //Simple test to check if the script runs successfully
    int runTest(const std::string& filename) {
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


    bool compareFiles(const std::string& file1Path, const std::string& file2Path) {
        std::ifstream file1(file1Path);
        std::ifstream file2(file2Path);

        // Check if either file failed to open
        if (!file1.is_open() || !file2.is_open()) {
            std::cerr << "Error: One or both files could not be opened." << std::endl;
            return false;
        }

        std::string line1, line2;

        // Compare the files line by line
        while (std::getline(file1, line1) && std::getline(file2, line2)) {
            // Trim whitespace and ignore line-ending differences
            line1 = trim(line1);
            line2 = trim(line2);

            if (line1 != line2) {
                return false;
            }
        }

        // Check if either file has more lines than the other
        if (file1.eof() != file2.eof()) {
            return false;
        }

        return true;
    }

};
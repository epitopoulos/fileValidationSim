#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

class FlashModule {
public:
    void setExecFilename(const std::string& filename) {
        if (std::filesystem::exists(filename)) {
            std::ofstream outFile("/tmp/test_code_filename.txt");
            if (outFile.is_open()) {
                outFile << filename;
                outFile.close();
                std::cout << "Code file " << filename << " flashed successfully.\n";
            } else {
                std::cerr << "Error: Unable to open file for writing." << std::endl;
            }
        } else {
            std::cerr << "Error: File does not exist." << std::endl;
        }
    }

    std::string getExecFilename() {
        std::ifstream inFile("/tmp/test_code_filename.txt");
        std::string filename;
        if (inFile.is_open()) {
            std::getline(inFile, filename);
            inFile.close();
        } else {
            std::cerr << "Error: Unable to open file for reading." << std::endl;
        }
        return filename;
    }
};
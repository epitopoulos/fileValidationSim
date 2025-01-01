#include <iostream>
#include <cstdlib>

class TestModule {
public:
    //Simple test to check if the script runs successfully
    void runTest(const std::string& filename) {
        std::string command = "python " + filename;
        int result = system(command.c_str());
        if (result == 0) {
            std::cout << "Test executed successfully\n";
        } else {
            std::cout << "Test failed\n";
        }
    }
};
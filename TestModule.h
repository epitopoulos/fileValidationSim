#include <iostream>
#include <cstdlib>

class TestModule {
public:
    //Simple test to check if the script runs successfully
    int runTest(const std::string& filename) {
        std::string command = "python " + filename;
        int result = system(command.c_str());
        return result;
    }
};
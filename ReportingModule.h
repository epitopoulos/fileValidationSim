#include <iostream>

class ReportingModule {
public:
    //if success is 0, the test passed successfully
    void reportResult(bool success) {
        if (!success) {
            std::cout << "Test passed successfully!\n";
        } else {
            std::cout << "Test failed.\n";
        }
    }
};
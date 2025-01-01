#include <iostream>

class ReportingModule {
public:
    void reportResult(bool success) {
        if (success) {
            std::cout << "Test passed successfully!\n";
        } else {
            std::cout << "Test failed.\n";
        }
    }
};
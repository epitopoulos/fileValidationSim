#include <iostream>
#include <fstream>

class ReportingModule {
public:
    void reportResult(bool success) {
        std::ofstream resultFile("/tmp/reportResult.txt");
        if (resultFile.is_open()) {
            if (!success) {
                resultFile << "Test passed successfully!\n";
            } else {
                resultFile << "Test failed.\n";
            }
            resultFile.close();
        } else {
            std::cerr << "Unable to open result file.\n";
        }
    }
};
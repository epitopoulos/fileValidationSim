#include <string>

class FlashModule {
private:
    std::string ExecutedFilename;

public:
    void setExecFilename(const std::string& filename) {
        ExecutedFilename = filename;
    }

    std::string getExecFilename() {
        return ExecutedFilename;
    }
};
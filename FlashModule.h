#include <string>
#include <filesystem>

class FlashModule {
private:
    std::string ExecutedFilename;

public:
    void setExecFilename(const std::string& filename) {
        if (std::filesystem::exists(filename)) {
            ExecutedFilename = filename;
            std::cout << "Code file " << ExecutedFilename << " flashed successfully.\n";
        } else {
            std::cerr << "Error: File does not exist." << std::endl;
        }
    }

    std::string getExecFilename() {
        return ExecutedFilename;
    }
};
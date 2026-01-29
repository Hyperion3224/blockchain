#include <string>

class Logger{
private:

public:
    void log(std::string expected, std::string actual, std::string message = "");
};
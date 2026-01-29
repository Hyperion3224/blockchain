#include "test_logger.hpp"
#include <iostream>

void Logger::log(std::string expected, std::string actual, std::string message){
    if (expected == actual){ return; }
    std::cout << "Expected: " << expected << std::endl
        << "Actual: " << actual << std::endl;

    if (!message.empty()){
        std::cout << message << std::endl;
    }
}
#include "ledgerio.hpp"
#include <iostream>
#include <cstdlib>

namespace fs = std::filesystem;

LedgerIO::LedgerIO(std::string _filename):
    filename(_filename){
    #if defined(_WIN32) || defined(_WIN64) 
    #elif defined(__linux__)
        dirPath = fs::path(std::getenv("HOME"));
        dirPath /= ".blockchain";
    #elif defined(__APPLE__) && defined(__MACH__)
    #elif defined(__unix__) || defined(__unix)
    #else
    #endif

    if(!fs::exists(dirPath)){
        fs::create_directories(dirPath);
    }

    std::cout << dirPath / filename << std::endl;
};

void LedgerIO::write(std::string buffer){
    std::ofstream(dirPath / "blocks" / filename, std::ios::app) << buffer;
}

std::string LedgerIO::read(){
    std::string buffer;
    std::ifstream(dirPath / "blocks" / filename) >> buffer;
    return buffer;
}
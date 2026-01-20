#include "ledgerio.hpp"

LedgerIO::LedgerIO(std::string _filename):
    filename(_filename){};

void LedgerIO::write(std::string buffer){
    std::ofstream(filename, std::ios::app) << buffer;
}

std::string LedgerIO::read(){
    std::string buffer;
    std::ifstream(filename) >> buffer;

    return buffer;
}
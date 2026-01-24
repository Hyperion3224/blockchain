#include <string>
#include <cstdint>
#include <bit>
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void print(auto buffer){
    std::cout << buffer << std::endl;
}

int main(){
    uint32_t num = 0x1; 
    std::string s = std::bit_cast<std::string>(num);

    print(s);
}
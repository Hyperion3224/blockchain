#include <vector>
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
    uint32_t num = 0xFFFFFFFF;
    std::string str("hello");

    std::string s(reinterpret_cast<char*>(&num), sizeof(num));

    print(s);


}
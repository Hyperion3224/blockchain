#include <vector>
#include <string>
#include <cstdint>
#include <bit>
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include "serialize.hpp"
#include "deserialize.hpp"

namespace fs = std::filesystem;

void print(auto buffer){
    std::cout << buffer << std::endl;
}

int main(){
    std::string str("Hello World");
    std::string str2;

    std::vector<uint8_t> buffer;

    serializeString(buffer, str);
    str2 = deserializeString(buffer);

    print(str2);
}

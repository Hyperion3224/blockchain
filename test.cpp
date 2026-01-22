#include <string>
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void print(auto buffer){
    std::cout << buffer << std::endl;
}

int main(){
    fs::path p(std::getenv("HOME"));
    p /= "CryptoCur";
    print(p);
}
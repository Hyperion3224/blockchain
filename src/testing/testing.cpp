#include "block.hpp"
#include <string>
#include <iostream>

using std::string;

int main()
{
    string firstHash = "000000000000000000";
    string str("Hello World");
    string str2("Hello World 2");

    Block a(firstHash, str, 101010);
    Block b(a.getHash(), str2, 202020);

    std::cout << a.getHash() << std::endl;
    std::cout << b.getHash() << std::endl;
}
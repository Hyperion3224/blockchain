#include "block.hpp"
#include "blockbuilder.hpp"
#include <string>
#include <iostream>

using std::string;

int main(){
    Block a = BlockBuilder()
        .addPrevHash("00000000000000000000000000000000000")
        .addData("Hello World")
        .addDifficultyTarget(1)
        .mineHash()
        .build();

    std::cout << a.toString();
}
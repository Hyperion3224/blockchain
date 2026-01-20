#include "block.hpp"
#include "blockbuilder.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

int main(){
    std::vector<Block> blockchain;

    blockchain.push_back(
        BlockBuilder()
            .addPrevHash(std::string(64, '0'))
            .addData("Hello World")
            .addDifficultyTarget(2)
            .mineHash()
            .build()
    );

    for(int i = 1; i < 50; i++){
        blockchain.push_back(
            BlockBuilder()
                .addPrevHash(blockchain.back().getHash())
                .addData("Hello World" + std::to_string(i))
                .addDifficultyTarget(2)
                .mineHash()
                .build()
        );
    }

    for (Block b: blockchain){
        std::cout << b.toString() << std::endl;
    }
}
#include "block.hpp"
#include "blockbuilder.hpp"
#include "ledgerio.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

int main(){
    std::vector<Block> blockchain;
    LedgerIO ledger;

    blockchain.push_back(
        BlockBuilder()
            .addPrevHash(std::string(64, '0'))
            .addData(std::string("This is the data recorded within my block"))
            .addDifficultyTarget(2)
            .mineHash()
            .build()
    );

    for(int i = 1; i < 5; i++){
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
        ledger.writeBlock(b.dton());
    }
}
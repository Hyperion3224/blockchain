#include "block.hpp"
#include "blockbuilder.hpp"
#include "ledgerio.hpp"
#include "chainverifier.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

int main(){
    std::vector<Block> blockchain;
    LedgerIO ledgerIO;

    blockchain.push_back(
        BlockBuilder()
        .addPrevHash(std::string(64, '0'))
        .addData(std::string("This is the data recorded within my block"))
        .addDifficultyTarget(2)
        .mineHash()
        .build()
    );

    for (int i = 1; i < 10; i++){
        blockchain.push_back(
            BlockBuilder()
            .addPrevHash(blockchain.back().getHash())
            .addData("This is the data recorded inside of block " + std::to_string(i))
            .addDifficultyTarget(2)
            .mineHash()
            .build()
        );
    }


    for (Block b : blockchain){
        ledgerIO.writeBlock(b.dton());
    }

    blockchain = ledgerIO.readActiveFile();

    std::cout << isValidBlockChain(blockchain) << std::endl;

    return 0;
}
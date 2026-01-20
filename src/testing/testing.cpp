#include "block.hpp"
#include "blockbuilder.hpp"
#include "ledgerio.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

int main(){
    std::vector<Block> blockchain;

    blockchain.push_back(
        BlockBuilder()
            .addPrevHash(std::string(64, '0'))
            .addData(std::string(30, 'x'))
            .addDifficultyTarget(2)
            .mineHash()
            .build()
    );

    LedgerIO ledger("IOTest.txt");

    ledger.write("test");
    std::cout << ledger.read();

    for (Block b: blockchain){
        std::cout << b.toString() << std::endl;
    }
}
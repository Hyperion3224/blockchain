#include "chainverifier.hpp"
#include "blockbuilder.hpp"
#include <iostream>


int isValidBlockChain(std::vector<Block>& blockchain){
    std::string chainPrevHash = firstInChain;

    for (Block& b : blockchain){
        if (b.getPrevHash() != chainPrevHash){
            std::cerr << b.getPrevHash() << " =previous hash not equal= " << chainPrevHash << std::endl;
            std::cerr << b.getData() << std::endl;
            return -1;
        }

        BlockBuilder bb;
        Block tempBlock = bb.addData(b.getData())
            .addDifficultyTarget(2)
            .addPrevHash(b.getPrevHash())
            .setNonce(b.getNonce())
            .build();

        if (tempBlock.getHash() != b.getHash()){
            std::cerr << b.getHash() << " =derived hash not equal= " << tempBlock.getHash() << std::endl;
            return -1;
        }

        chainPrevHash = b.getHash();
    }
    return 0;
}
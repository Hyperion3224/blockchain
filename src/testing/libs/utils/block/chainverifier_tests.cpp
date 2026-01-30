#include "chainverifier.hpp"
#include "blockbuilder.hpp"
#include "test_logger.hpp"

#include <vector>
#include <iostream>

int run_chainverifier_tests(){
    std::vector<Block> chain;
    BlockBuilder bb;

    chain.push_back(bb.build());

    std::cout << "CV";

    for (int i = 1; i < 5; i++){
        chain.push_back(
            bb.addPrevHash(chain.back().getHash()).build()
        );
    }

    int chainCheckVal = isValidBlockChain(chain);
    if (chainCheckVal != 0){
        Logger l;
        l.log(std::to_string(chainCheckVal), "0", "verifier has not passed its test");
        return -1;
    }

    std::cout << "Chain Verifier tests passed" << std::endl;
    return 0;
}
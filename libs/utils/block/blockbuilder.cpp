#include "block.hpp"
#include "blockbuilder.hpp"
#include "picosha2.h"

BlockBuilder& BlockBuilder::mineHash() {
    // 1. Create a temporary block to test hashes
    // 2. Loop and increment nonce until it is a valid hash
    
    bool found = false;
    while (!found) {
        std::string tHash = computeHash();
        if (tHash.substr(0, difficultyTarget) == difficultyString) {
            found = true;
            hash = tHash;
        } else {
            nonce++;
        }
    }
    return *this;
}

std::string BlockBuilder::computeHash(){
    if (data.size() + prevHash.size() + sizeof(nonce) >= MAX_BLOCK_SIZE){
        throw std::invalid_argument("Sizes of block elements is too large to hash");
    }

    return picosha2::hash256_hex_string(data + prevHash + std::to_string(nonce));
}

Block BlockBuilder::build(){
    if(hash.empty()){
        hash = computeHash();
    }
    
    return Block(prevHash, data, nonce, hash);
}
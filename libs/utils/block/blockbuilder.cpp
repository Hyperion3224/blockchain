#include "block.hpp"
#include "blockbuilder.hpp"
#include "serialize.hpp"
#include "picosha2.h"

BlockBuilder& BlockBuilder::mineHash(){
    bool found = false;
    while (!found){
        std::string tHash = computeHash();
        if (tHash.substr(0, difficultyTarget) == difficultyString){
            found = true;
            hash = tHash;
        }
        else{
            nonce++;
        }
    }
    return *this;
}

std::string BlockBuilder::computeHash(){
    if (data.size() + prevHash.size() + sizeof(nonce) >= MAX_BLOCK_SIZE){
        throw std::invalid_argument("Sizes of block elements is too large to hash");
    }
    std::string content;

    std::vector<uint8_t> nonceBytes;
    serializeUInt32(nonceBytes, nonce);

    content.append(data)
        .append(prevHash)
        .append(reinterpret_cast<char*>(nonceBytes.data()), sizeof(nonce));

    return picosha2::hash256_hex_string(content);
}

Block BlockBuilder::build(){
    if (hash.empty()){
        hash = computeHash();
    }

    return Block(prevHash, data, nonce, hash);
}
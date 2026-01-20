#include "Block.hpp"
#include <stdexcept>
#include "../crypto/picosha2.h"

Block::Block(const std::string& _prevHash,
    const std::string& _data,
    int _nonce)
    : data(_data), prevHash(_prevHash), nonce(_nonce){

    //precompute difficulty hash so a substring comparison is used later for mining

    for (int i = 0; i < difficultyTarget; i++){
        difficultyString += "0";
    }

    hash = computeHash();
}

std::string Block::computeHash(){
    if (data.size() + prevHash.size() + sizeof(nonce) >= 1048576){
        throw std::invalid_argument("Sizes of block elements is too large to hash");
    }

    return picosha2::hash256_hex_string(data + prevHash + std::to_string(nonce));
}

bool Block::isValidHash(std::string hash){
    if (hash.length() < difficultyTarget){ return false; }
    return (hash.substr(difficultyTarget) == difficultyString);
}
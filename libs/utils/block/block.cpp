#include "block.hpp"
#include <stdexcept>

Block::Block(const std::string& _prevHash,
    const std::string& _data,
    uint32_t _nonce,
    const std::string& _hash)
    : data(_data), prevHash(_prevHash), nonce(_nonce), hash(_hash){
}

std::string Block::toString(){
    return "data: " + data + ",\nnonce: " + std::to_string(nonce) + ",\nprevHash: " + prevHash + ",\nhash: " + hash;
}

std::string Block::dton(){
    return std::to_string(nonce) + prevHash + hash + data;
}


#include "block.hpp"
#include "serialize.hpp"
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

std::vector<uint8_t> Block::dton(){
    std::vector<uint8_t> buffer;

    serializeUInt32(buffer, nonce);
    serializeString(buffer, hash);
    serializeString(buffer, prevHash);
    serializeString(buffer, data);

    return buffer;
}

Block ntod(std::vector<uint8_t> buffer){

}
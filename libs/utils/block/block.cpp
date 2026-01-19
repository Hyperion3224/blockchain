#include "Block.hpp"
#include <stdexcept>
#include "../crypto/picosha2.h"

Block::Block(const std::string &_prevHash,
             const std::string &_data,
             int _nonce)
    : data(_data), prevHash(_prevHash), nonce(_nonce)
{
    hash = computeHash();
}

std::string Block::computeHash()
{
    if (data.size() + prevHash.size() + sizeof(nonce) >= 1048576)
    {
        throw std::invalid_argument("Sizes of block elements is too large to hash");
    }

    return picosha2::hash256_hex_string(data + prevHash + std::to_string(nonce));
}
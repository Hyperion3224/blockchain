#pragma once

#include <string>
#include <cstdint>
#include <vector>

#define MAX_BLOCK_SIZE 1048576

using std::uint32_t;
using std::uint8_t;

class Block{
private:
    std::string data;
    std::string prevHash;
    uint32_t nonce;
    std::string hash = "";

public:
    Block(const std::string& _prevHash,
        const std::string& _data,
        uint32_t _nonce,
        const std::string& _hash
    );

    std::string toString();
    std::vector<uint8_t> dton();
    Block ntod(std::vector<uint8_t> buffer);

    std::string getData() const{ return data; }
    std::string getPrevHash() const{ return prevHash; }
    uint32_t getNonce() const{ return nonce; }
    std::string getHash() const{ return hash; }
};
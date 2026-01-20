#pragma once

#include <string>

#define MAX_BLOCK_SIZE 1048576

class Block{
private:
    std::string data;
    std::string prevHash;
    uint nonce;
    std::string hash = "";

public:
    Block(const std::string& _prevHash,
        const std::string& _data,
        uint _nonce,
        const std::string& _hash
    );

    std::string toString();

    std::string getData() const{ return data; }
    std::string getPrevHash() const{ return prevHash; }
    uint getNonce() const{ return nonce; }
    std::string getHash() const{ return hash; }
};
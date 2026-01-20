#pragma once

#include <string>

class Block{
private:
    std::string data;
    std::string prevHash;
    int nonce;
    int difficultyTarget = 1;
    std::string difficultyString = "";

    std::string hash = "";

    bool Block::isValidHash(std::string hash);

public:
    Block(const std::string& _prevHash,
        const std::string& _data,
        int _nonce);

    std::string Block::computeHash();
    std::string toString();

    std::string getData() const{ return data; }
    std::string getPrevHash() const{ return prevHash; }
    std::string getHash() const{ return hash; }
    int getNonce() const{ return nonce; }
};
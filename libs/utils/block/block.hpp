#pragma once

#include <string>

class Block
{
private:
    std::string data;
    std::string prevHash;
    int nonce;
    std::string hash = "";

public:
    Block(const std::string &_prevHash,
          const std::string &_data,
          int _nonce);

    std::string computeHash();

    std::string getData() const { return data; }
    std::string getPrevHash() const { return prevHash; }
    std::string getHash() const { return hash; }
    int getNonce() const { return nonce; }
};
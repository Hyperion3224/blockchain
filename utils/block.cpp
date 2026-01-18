#include <string>
#include <stdexcept>

#include "picosha2.h"

using std::string;

class Block
{
private:
    string data;
    string prevHash;
    int nonce;

    string hash = "";

public:
    Block(string &_prevHash,
          string &_data,
          int _nonce)
        : data(_data),
          prevHash(_prevHash),
          nonce(_nonce)
    {

        computeHash();
    }

    string computeHash()
    {
        if (data.size() + prevHash.size() + sizeof(nonce) >= 1048576)
        {
            throw new std::invalid_argument("Sizes of block elements is too large to hash");
        }

        return picosha2::hash256_hex_string(data + prevHash + std::to_string(nonce));
    }

    string getData() { return data; }
    string getPrevHash() { return prevHash; }
    string getHash() { return hash; }
    int getNonce() { return nonce; }
};
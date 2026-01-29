#pragma once

#include <string>
#include <cstdint>

#ifndef DEFAULT_BLOCK_HASH 
#define DEFAULT_BLOCK_HASH "df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119" 
#endif

class Block;

class BlockBuilder{
private:
    std::string data = "";
    std::string prevHash = "";
    uint32_t nonce = 0;
    int difficultyTarget = 1;
    std::string difficultyString = "";

    std::string hash = "";

    std::string computeHash();
public:
    BlockBuilder() = default;

    BlockBuilder& addData(std::string _data){ data = _data; return *this; };
    BlockBuilder& addPrevHash(std::string _prevHash){ prevHash = _prevHash; return *this; };
    BlockBuilder& setNonce(uint32_t _nonce){ nonce = _nonce; return *this; };
    inline BlockBuilder& addDifficultyTarget(int _target){
        difficultyTarget = _target;
        difficultyString = std::string(_target, '0');
        return *this;
    };

    BlockBuilder& mineHash();
    Block build();
};
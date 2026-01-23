#include <string>

class Block;

class BlockBuilder{
private:
    std::string data = "";
    std::string prevHash = "";
    size_t nonce = 0;
    int difficultyTarget = 1;
    std::string difficultyString = "";

    std::string hash = "";

    std::string computeHash();
public:
    BlockBuilder() = default;

    BlockBuilder& addData(std::string _data){ data = _data; return *this; };
    BlockBuilder& addPrevHash(std::string _prevHash){ prevHash = _prevHash; return *this; };
    inline BlockBuilder& addDifficultyTarget(int _target){
        difficultyTarget = _target;
        difficultyString = std::string(_target, '0');
        return *this;
    };

    BlockBuilder& mineHash();
    Block build();
};
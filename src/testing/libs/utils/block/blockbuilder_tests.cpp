#include "blockbuilder.hpp"
#include "block.hpp"
#include "test_logger.hpp"

int run_blockbuilder_tests(){
    int ret = 0;
    BlockBuilder bb;
    Logger l;

    Block temp = bb.build();
    l.log(temp.getHash(), DEFAULT_BLOCK_HASH, "Default variables failed");

    temp = bb.addData(std::string(1000000, '0'))
        .addPrevHash(std::string(64, '0'))
        .mineHash()
        .build();

    l.log(sizeof(temp.dton()), MAX_BLOCK_SIZE, "Block is too large");

    return ret;
}
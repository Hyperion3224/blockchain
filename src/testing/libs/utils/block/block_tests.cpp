#include "block.hpp"
#include "test_logger.hpp"

#include <cstdint>
#include <vector>


int run_block_tests(){
    int ret = 0;

    std::string maxData(MAX_BLOCK_SIZE - (2 * HASH_SIZE) - sizeof(uint32_t), '0');
    std::string goodHash(64, '0');

    Block maxSizeBlock();

    return ret;
}
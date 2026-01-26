#pragma once

#include <string>
#include <filesystem>
#include <vector>
#include <cstdint>

#include "block.hpp"

#define MAX_MB_DATA_SIZE 128000000

#define BLOCK_FOLDER "testing_blocks"
#define BLOCK_FILE_TITLE "BlockchainBLK"
#define BLOCK_FILE_EXT ".dat"

#define MAGIC_FORMAT 0x4A443234
#define MAGIC_VERSION  0x01

#define PACKING_FORMAT 0x0

class LedgerIO{
private:
    std::filesystem::path activeFilePath;
    std::filesystem::path dirPath;

    std::filesystem::path getLastDat();
    int getNumFromBlock(std::filesystem::path path);
    void initBlockFile(std::filesystem::path path, uint32_t num);

public:
    LedgerIO();

    void writeBlock(std::vector<uint8_t> buffer);
    std::vector<Block> readActiveFile();
};
#pragma once

#include <bits/stdc++.h>
#include <string>
#include <filesystem>

#define MAX_MB_DATA_SIZE 128000000
#define BLOCK_FOLDER "testing_blocks"
#define DAT_FILE_TITLE "BlockchainBLK"

class LedgerIO{
private:
    std::filesystem::path activeFilePath;
    std::filesystem::path dirPath;

    std::filesystem::path getLastDat();
    int getNumFromBlock(std::filesystem::path path);

public:
    LedgerIO();

    void writeBlock(std::vector<uint8_t> buffer);
    std::string readTop();
};
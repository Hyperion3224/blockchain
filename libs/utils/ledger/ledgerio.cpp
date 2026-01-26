#include "ledgerio.hpp"
#include "serialize.hpp"
#include "deserialize.hpp"
#include "blockbuilder.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstring>

namespace fs = std::filesystem;

LedgerIO::LedgerIO(){
    // Setting working directory dependent on the OS filesystem
#if defined(_WIN32) || defined(_WIN64) 
    dirPath = fs::path(std::getenv("USERPROFILE"));
    dirPath /= ".blockchain";
#elif defined(__linux__)
    dirPath = fs::path(std::getenv("HOME"));
    dirPath /= ".blockchain";
#elif defined(__APPLE__) && defined(__MACH__)
#elif defined(__unix__) || defined(__unix)
#else
#endif

    if (!fs::exists(dirPath)){
        fs::create_directories(dirPath);
    }

    activeFilePath = getLastDat();
};

void LedgerIO::writeBlock(std::vector<uint8_t> buffer){
    const fs::path fullPath = dirPath / BLOCK_FOLDER;

    if (buffer.size() > MAX_MB_DATA_SIZE){
        std::cerr << "Failed to write buffer was too large" << std::endl;
        return;
    }

    if (!fs::exists(fullPath)){
        //if the block path doesnt exist then it will create it and init the first file
        initBlockFile(fullPath, 0x0);
    }
    else if (fs::file_size(activeFilePath) + buffer.size() > MAX_MB_DATA_SIZE){
        initBlockFile(fullPath, getNumFromBlock(activeFilePath) + 1);
    }

    std::ofstream file(activeFilePath, std::ios::binary | std::ios::app);
    if (file.is_open()){
        // 1/26/2026 12:39 AM order: Nonce Hash pHash Data
        file.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    }
    else{
        std::cerr << "Error opening file: " << activeFilePath << std::endl;
    }
}

std::vector<Block> LedgerIO::readActiveFile(){
    std::ifstream file(activeFilePath, std::ios::binary); // Open in binary mode!

    if (file.is_open()){
        std::vector<Block> blocks;

        char mfn[4];
        file.read(mfn, 4);
        char mfv;
        file.read(&mfv, 1);

        for (int i = 0; i < 5; i++){
            BlockBuilder bb;

            // 1. Helper for Nonce
            uint32_t nonce;
            std::vector<uint8_t> uintBuffer(4);
            file.read(reinterpret_cast<char*>(uintBuffer.data()), 4);
            nonce = deserializeUInt32(uintBuffer);

            // 2. Lambda to simplify String reading
            auto readString = [&](std::ifstream& f) -> std::string{
                std::vector<uint8_t> lenBuf(4);
                f.read(reinterpret_cast<char*>(lenBuf.data()), 4);
                uint32_t len = deserializeUInt32(lenBuf);

                // Prepare a buffer that contains [Length(4) + Data(len)] 
                // to satisfy your deserializeString() requirements
                std::vector<uint8_t> fullBuf = lenBuf;
                fullBuf.resize(4 + len);
                f.read(reinterpret_cast<char*>(fullBuf.data() + 4), len);
                return deserializeString(fullBuf);
                };

            std::string hash = readString(file);
            std::string prevHash = readString(file);
            std::string data = readString(file);

            Block tempBlock = bb.addData(data)
                .addDifficultyTarget(2)
                .addPrevHash(prevHash)
                .mineHash()
                .build();

            if (tempBlock.getNonce() != nonce ||
                tempBlock.getHash() != hash){
                std::cerr << "FAKE DATA DETECTED: " << std::endl <<
                    hash << " :: " << tempBlock.getHash() << std::endl <<
                    nonce << " :: " << tempBlock.getNonce() << std::endl;
            }
            else{
                blocks.push_back(tempBlock);
            }
        }
        return blocks;
    }
    return {};
}

fs::path LedgerIO::getLastDat(){
    fs::path lastDat("0");
    int lastDatNum = 0;

    fs::path fullPath(dirPath);
    fullPath /= BLOCK_FOLDER;

    if (!fs::exists(fullPath)){
        fs::create_directories(fullPath);
    }

    if (fs::is_empty(fullPath)){
        //if the block path doesnt exist then it will create it and init the first file
        initBlockFile(fullPath, 0x0);
    }

    for (auto& entry : fs::directory_iterator(fullPath)){
        int number = getNumFromBlock(entry.path());
        if (fs::is_regular_file(entry.status())){
            if (number >= lastDatNum){
                lastDat = entry.path();
                lastDatNum = number;
            }
        }
    }

    return lastDat.replace_extension(BLOCK_FILE_EXT);
}

int LedgerIO::getNumFromBlock(fs::path path){
    std::string stem = path.stem().string();
    std::string numberPart = stem.substr(std::strlen(BLOCK_FILE_TITLE));

    return std::stoi(numberPart);
}


void LedgerIO::initBlockFile(std::filesystem::path path, uint32_t num){
    std::string newFilename = std::string(BLOCK_FILE_TITLE) + std::to_string(num);
    activeFilePath = path / (newFilename + BLOCK_FILE_EXT);

    std::ofstream tempInitBlockDat(activeFilePath, std::ios::binary);

    //write magic filetype and version number;
    if (tempInitBlockDat.is_open()){
        std::vector<uint8_t> fmtBuff;
        uint8_t fmv = MAGIC_VERSION;
        serializeUInt32(fmtBuff, MAGIC_FORMAT);
        tempInitBlockDat.write(reinterpret_cast<const char*>(fmtBuff.data()), fmtBuff.size());
        tempInitBlockDat.write(reinterpret_cast<const char*>(&fmv), 1);
        tempInitBlockDat.close();

        if (tempInitBlockDat){
            std::cout << "Created new file: " << activeFilePath << std::endl;
        }
        else{
            std::cerr << "Write failed to: " << activeFilePath << std::endl;
        }
    }
    else{
        std::cerr << "Error opening file: " << activeFilePath << std::endl;
    }


}
#include "ledgerio.hpp"
#include <iostream>
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
    const fs::path fullToFile = fullPath / activeFilePath;

    if (buffer.size() > MAX_MB_DATA_SIZE){
        std::cerr << "Failed to write buffer was too large";
        return;
    }

    if (!fs::exists(fullPath)){
        //if the block path doesnt exist then it will create it and init the first file
        fs::create_directories(fullPath);
        std::ofstream tempInitBlockDat(fullPath / (std::string(DAT_FILE_TITLE) + "0"));
        tempInitBlockDat.close();
    }
    else if (fs::file_size(fullToFile) + buffer.size() > MAX_MB_DATA_SIZE){
        std::string newActiveFilename(
            DAT_FILE_TITLE +
            std::to_string(getNumFromBlock(activeFilePath) + 1)
        );
        std::ofstream openNewBlockDat(fullPath / newActiveFilename);
        openNewBlockDat.close();
        activeFilePath = fullPath / newActiveFilename;
        std::cout << "new dat file created:: " << newActiveFilename;
    }

    std::ofstream file(activeFilePath, std::ios::app);
    if (file.is_open()){
        for (uint8_t byte : buffer){
            file << byte;
        }
    }
    else{
        std::cerr << "Error opening file: " << activeFilePath;
    }
}

std::string LedgerIO::readTop(){
    std::string buffer;
    std::ifstream(activeFilePath) >> buffer;
    return buffer;
}

fs::path LedgerIO::getLastDat(){
    fs::path lastDat("0");
    int lastDatNum = 0;

    fs::path fullPath(dirPath);
    fullPath /= BLOCK_FOLDER;

    if (!fs::exists(fullPath)){
        //if the block path doesnt exist then it will create it and init the first file
        fs::create_directories(fullPath);
    }
    if (fs::is_empty(fullPath)){
        std::string newFilename = std::string(DAT_FILE_TITLE) + "0";
        std::ofstream tempInitBlockDat((fullPath / newFilename).string());
        tempInitBlockDat.close();
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

    return lastDat;
}

int LedgerIO::getNumFromBlock(fs::path path){
    std::string stem = path.stem().string();
    std::string numberPart = stem.substr(std::strlen(DAT_FILE_TITLE));

    return std::stoi(numberPart);
}
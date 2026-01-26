#include "deserialize.hpp"

uint32_t deserializeUInt32(std::vector<uint8_t>& inBuffer){
    uint32_t out = 0;

    if (inBuffer.size() >= 4){
        out =
            (static_cast<uint32_t>(inBuffer[0]) << 24) |
            (static_cast<uint32_t>(inBuffer[1]) << 16) |
            (static_cast<uint32_t>(inBuffer[2]) << 8) |
            (static_cast<uint32_t>(inBuffer[3]) << 0);
        return out;
    }
    else{
        std::cerr << "Error parsing uint32, buffer size was too small";
    }
}

std::string deserializeString(std::vector<uint8_t>& inBuffer){
    std::string out;
    uint32_t size = deserializeUInt32(inBuffer);

    if (size + 4 == inBuffer.size()){
        for (int i = 0; i < size; i++){
            out.push_back(static_cast<char>(inBuffer[4 + i]));
        }
        return out;
    }
    else{
        std::cerr << "Error parsing string, buffer did not fit size of string";
    }
}
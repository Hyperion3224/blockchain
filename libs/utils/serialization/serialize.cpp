#include "serialize.hpp"

void serializeString(std::vector<uint8_t>& outBuffer, std::string& str){
    outBuffer.reserve(outBuffer.size() + 4 + str.size());
    uint32_t len = static_cast<uint32_t>(str.size());

    serializeUInt32(outBuffer, len);

    outBuffer.insert(outBuffer.end(), str.begin(), str.end());
}

void serializeUInt32(std::vector<uint8_t>& outBuffer, uint32_t num){
    outBuffer.push_back((num >> 24) & 0xFF);
    outBuffer.push_back((num >> 16) & 0xFF);
    outBuffer.push_back((num >> 8) & 0xFF);
    outBuffer.push_back(num & 0xFF);
}

uint8_t deserializeUInt32(std::vector<uint8_t>& inBuffer){

}

std::string deserializeString(std::vector<uint8_t>& inBuffer, uint32_t size){

}
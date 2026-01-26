#include "deserialize.hpp"

uint32_t deserializeUInt32(std::vector<uint8_t>& inBuffer){
    if (inBuffer.size() < 4){
        std::cerr << "Error parsing uint32, buffer size was too small" << std::endl;
        return 0;
    }
    // Static cast and bitwise OR logic
    return (static_cast<uint32_t>(inBuffer[0]) << 24) |
        (static_cast<uint32_t>(inBuffer[1]) << 16) |
        (static_cast<uint32_t>(inBuffer[2]) << 8) |
        (static_cast<uint32_t>(inBuffer[3]) << 0);
}

std::string deserializeString(std::vector<uint8_t>& inBuffer){
    if (inBuffer.size() < 4) return "";
    uint32_t size = deserializeUInt32(inBuffer);

    if (size + 4 <= inBuffer.size()){ // Use <= to be safer
        return std::string(reinterpret_cast<char*>(inBuffer.data() + 4), size);
    }
    std::cerr << "Error: Buffer size mismatch for string" << std::endl;
    return "";
}
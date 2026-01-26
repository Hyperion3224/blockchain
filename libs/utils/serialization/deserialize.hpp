#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

uint32_t deserializeUInt32(std::vector<uint8_t>& inBuffer);
std::string deserializeString(std::vector<uint8_t>& inBuffer);
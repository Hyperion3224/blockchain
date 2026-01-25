#include <vector>
#include <string>
#include <cstdint>

void serializeString(std::vector<uint8_t>& outBuffer, std::string& str);
void serializeUInt32(std::vector<uint8_t>& outBuffer, uint32_t num);

uint8_t deserializeUInt32(std::vector<uint8_t>& inBuffer);
std::string deserializeString(std::vector<uint8_t>& inBuffer, uint32_t size);
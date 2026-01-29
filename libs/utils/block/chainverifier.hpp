#pragma once

#include <vector>
#include <string>
#include "block.hpp"

#define firstInChain std::string(64 , '0');

int isValidBlockChain(std::vector<Block>& blockchain);
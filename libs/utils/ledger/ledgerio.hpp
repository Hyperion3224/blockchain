#pragma once

#include <bits/stdc++.h>
#include <string>
#include <filesystem>

class LedgerIO{
    private:
        std::filesystem::path filename;
        std::filesystem::path dirPath;
        
    public:
        LedgerIO(std::string _filename);

        void write(std::string buffer);
        std::string read();
};
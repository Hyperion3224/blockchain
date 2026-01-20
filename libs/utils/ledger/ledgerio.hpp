#pragma once

#include <bits/stdc++.h>
#include <string>

class LedgerIO{
    private:
        std::string filename;
        
    public:
        LedgerIO(std::string _filename);

        void write(std::string buffer);
        std::string read();
};
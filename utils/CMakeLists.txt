add_library(utils
    block.cpp
    block.hpp
    picosha2.h
)

# Let consumers include headers from utils/ with: #include "block.hpp"
target_include_directories(utils
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

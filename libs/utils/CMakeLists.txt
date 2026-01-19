add_library(utilities
    block/block.cpp
)

target_include_directories(utilities
    PRIVATE
        crypto/
    PUBLIC
        block/
)
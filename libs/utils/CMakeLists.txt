add_library(utilities
    block/block.cpp
    block/blockbuilder.cpp
)

target_include_directories(utilities
    PRIVATE
        crypto/
    PUBLIC
        block/
)
add_library(utilities
    block/block.cpp
    block/blockbuilder.cpp
    ledger/ledgerio.cpp
    serialization/serialize.cpp
)

target_include_directories(utilities
    PRIVATE
        crypto/
        serialization/
    PUBLIC
        block/
        ledger/
)
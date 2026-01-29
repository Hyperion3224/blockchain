add_library(utilities
    block/block.cpp
    block/blockbuilder.cpp
    block/chainverifier.cpp
    ledger/ledgerio.cpp
    serialization/serialize.cpp
    serialization/deserialize.cpp
)

target_include_directories(utilities
    PRIVATE
        crypto/
    PUBLIC
        serialization/
        block/
        ledger/
)
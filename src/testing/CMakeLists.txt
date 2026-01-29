add_executable(playground
    testing.cpp
)
    
target_link_libraries(playground
    PRIVATE
        utilities
)

add_library(testing_logger
    libs/logging/test_logger.cpp
)

target_include_directories(testing_logger
    PUBLIC
        libs/logging/
)

add_library(testing_suite
    libs/utils/block/block_tests.cpp
    libs/utils/block/blockbuilder_tests.cpp
    libs/utils/block/chainverifier_tests.cpp

    libs/utils/ledger/ledgerio_tests.cpp
    libs/utils/ledger/ledgerverifier_tests.cpp

    libs/utils/serialization/deserialize_tests.cpp
    libs/utils/serialization/serialize_tests.cpp
)

target_include_directories(testing_suite
    PUBLIC
        libs/block/
        libs/ledger/
        libs/serialization/
        libs/logging/
)

target_link_libraries(testing_suite
    utilities
    testing_logger
)


add_executable(tester
    tester.cpp
)

target_link_libraries(tester
    PRIVATE
        testing_suite   
)
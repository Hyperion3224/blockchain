add_executable(test_app
    testing.cpp
)

target_link_libraries(test_app
    PRIVATE
        utilities
)

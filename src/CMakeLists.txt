add_executable(mainApplication
    mainApplication.cpp
)

target_link_libraries(mainApplication
    PRIVATE
        networking
        utils
)

# If mainApplication includes headers that live in src/ itself, optionally:
target_include_directories(mainApplication
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

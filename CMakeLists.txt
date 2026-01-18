cmake_minimum_required(VERSION 3.20)

project(MyApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: put all binaries in one place
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Build libraries first (order doesn't *usually* matter, but it's nice/readable)
add_subdirectory(utils)
# add_subdirectory(networking)
add_subdirectory(src)

# If you want your test.cpp as a separate executable:
add_executable(test_app test.cpp)
# link test_app to whatever you need:
target_link_libraries(test_app PRIVATE utils)

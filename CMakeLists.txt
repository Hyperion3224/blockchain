cmake_minimum_required(VERSION 4.1)

project(Blockchain VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(networking)
add_subdirectory(src)
add_subdirectory(utils)
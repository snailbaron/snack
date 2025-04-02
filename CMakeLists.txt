cmake_minimum_required(VERSION 3.12)

project(snack)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(snack
    stream.cpp
    token.cpp
)
target_include_directories(snack PUBLIC include)

add_subdirectory(tools)

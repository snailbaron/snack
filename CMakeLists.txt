cmake_minimum_required(VERSION 3.0)

project(snack)

add_library(snack
    token.cpp
)
target_include_directories(snack PUBLIC include)

add_subdirectory(tools)

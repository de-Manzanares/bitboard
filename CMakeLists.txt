cmake_minimum_required(VERSION 3.25)
project(bitboard)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE FUNCTIONS "./functions/*.cpp")
add_executable(bitboard main.cpp ${FUNCTIONS})

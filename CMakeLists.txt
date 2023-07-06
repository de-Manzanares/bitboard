cmake_minimum_required(VERSION 3.25)
project(bitboard)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(bitboard source/addPiece.cpp
                        source/addReplaceCommand.cpp
                        source/coordinateIndex.cpp
                        source/fenCommand.cpp
                        source/fenDecode.cpp
                        source/fenEncode.cpp
                        source/main.cpp
                        source/moveCommand.cpp
                        source/pieceSearch.cpp
                        source/printBitBoard.cpp
                        source/subtractPiece.cpp)

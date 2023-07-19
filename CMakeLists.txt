cmake_minimum_required(VERSION 3.25)
project(bitboard)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(bitboard source/addReplaceCommand.cpp
                        source/bitwise.cpp
                        source/FEN.cpp
                        source/indices.cpp
                        source/main.cpp
                        source/moveBishop.cpp
                        source/moveCommand.cpp
                        source/moveKing.cpp
                        source/moveKnight.cpp
                        source/movePawn.cpp
                        source/moveQueen.cpp
                        source/moveRook.cpp
                        source/printAllMoves.cpp
                        source/printBitBoard.cpp
                        source/calculateRange.cpp
                        source/sideInfluence.cpp)

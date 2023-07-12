cmake_minimum_required(VERSION 3.25)
project(bitboard)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(bitboard source/addPiece.cpp
                        source/addReplaceCommand.cpp
                        source/calculateMovesDiagonal.cpp
                        source/calculateMovesHorizontal.cpp
                        source/calculateMovesVertical.cpp
                        source/coordinateIndex.cpp
                        source/fenCommand.cpp
                        source/fenDecode.cpp
                        source/fenEncode.cpp
                        source/main.cpp
                        source/moveCommand.cpp
                        source/moveBishop.cpp
                        source/moveKing.cpp
                        source/moveKnight.cpp
                        source/movePawn.cpp
                        source/moveRook.cpp
                        source/moveQueen.cpp
                        source/pieceSearch.cpp
                        source/printAllMoves.cpp
                        source/printBitBoard.cpp
                        source/printVector.cpp
                        source/rank_and_file.cpp
                        source/subtractPiece.cpp
                        source/squareSearch.cpp)

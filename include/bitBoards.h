/* 
    Copyright (C) 2023 de-Manzanares

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Contact:
    If you have any questions, comments, or suggestions,
    you can reach me at <git.in.touch@dmanz.org>
*/

/// @file   bitBoards.h
/// @author de-Manzanares
/// @brief  Header file for bitBoards

// include guard
#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Board
struct ChessBoard {
    uint64_t black_pawn   = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_night  = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_bishop = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_rook   = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_queen  = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_king   = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t white_Pawn   = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
    uint64_t white_Night  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
    uint64_t white_Bishop = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
    uint64_t white_Rook   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
    uint64_t white_Queen  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
    uint64_t white_King   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;
    bool whiteKingMoved = false;
    bool blackKingMoved = false;
    bool whiteKingSideRookMoved = false;
    bool whiteQueenSideRookMoved = false;
    bool blackKingSideRookMoved = false;
    bool blackQueenSideRookMoved = false;
};

// Functions
void    addPiece                (char piece, int index, ChessBoard& board);
void    addReplaceCommand       (stringstream& ss, ChessBoard& board);
void    calculateMovesDiagonal  (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMovesHorizontal(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMovesVertical  (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMovePawn       (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMoveKnight    (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    cleanRange              (vector<int>& range);
int     coordinateIndex         (const string& coordinate);
void    fenCommand              (stringstream& ss, ChessBoard& board);
void    fenDecode               (string& fenIn, ChessBoard& board);
void    fenEncode               (ChessBoard& board);
char    getFile                 (int index);
string  indexToAlgebraic        (int index);
bool    isInFile                (char file, int index);
bool    isInFile_A              (int indexFrom);
bool    isInFile_B              (int indexFrom);
bool    isInFile_C              (int indexFrom);
bool    isInFile_D              (int indexFrom);
bool    isInFile_E              (int indexFrom);
bool    isInFile_F              (int indexFrom);
bool    isInFile_G              (int indexFrom);
bool    isInFile_H              (int indexFrom);
bool    isInRank_1              (int indexFrom);
bool    isInRank_2              (int indexFrom);
bool    isInRank_7              (int indexFrom);
bool    isInRank_8              (int indexFrom);
void    moveCommand             (stringstream& ss, ChessBoard& board);
bool    movePawn                (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveKnight              (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveBishop              (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveRook                (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveQueen               (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveKing                (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
void    movePiece               (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
char    pieceSearch             (int index, const ChessBoard& board);
void    printAllMoves           (ChessBoard& board);
void    printBitBoard           (ChessBoard& board);
void    printVector             (vector<int>& range);
void    printVectorAlgebraic    (vector<int>& range);
bool    rangeValidation         (std::vector<int> range, int indexTo);
std::vector<int> squareSearch   (char pieceFrom, int& flag, int& canMove , int indexTo, ChessBoard& board);
void    subtractPiece           (char piece, int index, ChessBoard& board);

#endif // BITBOARDS_H

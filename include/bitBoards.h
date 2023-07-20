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
/// @brief  `ChessBoard` struct and function prototypes.

// include guard
#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Important variables
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
    uint64_t black_pieces = black_pawn | black_night | black_bishop | black_rook | black_queen | black_king;
    uint64_t white_pieces = white_Pawn | white_Night | white_Bishop | white_Rook | white_Queen | white_King;
    bool whiteToMove = true;
    int  halfMoveCount = 0;
    bool whiteKingMoved = false;
    bool blackKingMoved = false;
    bool whiteKingSideRookMoved  = false;
    bool whiteQueenSideRookMoved = false;
    bool blackKingSideRookMoved  = false;
    bool blackQueenSideRookMoved = false;
};

// Functions
void    updateBoard                 (ChessBoard& board);
void    addPiece                    (char piece, int index, ChessBoard& board);
void    addReplaceCommand           (stringstream& ss, ChessBoard& board);
void    calculateMoveKnight         (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMovePawn           (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    calculateMovesDiagonal      (char pieceFrom, int indexFrom, vector<int>& range, const ChessBoard& board);
void    calculateMovesHorizontal    (char pieceFrom, int indexFrom, vector<int>& range, const ChessBoard& board);
void    calculateMovesVertical      (char pieceFrom, int indexFrom, vector<int>& range, const ChessBoard& board);
void    calculateMovesHelper        (char pieceFrom, vector<int>& range, int& flag, int& canMove,
                                        const vector<int>& moves, int limit, const ChessBoard& board);
vector<int> squareSearch            (char pieceFrom, int& flag, int& canMove, int indexTo, const ChessBoard& board);
void    calculateRange              (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
void    cleanRange                  (vector<int>& range);
int     coordinateToIndex             (const string& coordinate);
void    fenCommand                  (stringstream& ss, ChessBoard& board);
void    fenDecode                   (string& fenIn, ChessBoard& board);
void    fenEncode                   (ChessBoard& board);
char    getFile                     (int index);
int     getRank                     (int index);
string  indexToCoordinate           (int index);
bool    moveBishop                  (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
void    moveCommand                 (stringstream& ss, ChessBoard& board);
bool    moveKing                    (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveKnight                  (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
void    movePiece                   (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    movePawn                    (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveQueen                   (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveRook                    (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
char    pieceSearch                 (int index, const ChessBoard& board);
void    printAllMoves               (ChessBoard& board);
void    printBitBoard               (ChessBoard& board);
void    printCoordinates            (const vector<int>& range);
bool    rangeValidation             (const vector<int>& range, int indexTo);
vector<int> sideInfluence           (char side, ChessBoard& board);
vector<int> sideInfluenceVerbose    (char side, ChessBoard& board);
void    subtractPiece               (char piece, int index, ChessBoard& board);

#endif // BITBOARDS_H

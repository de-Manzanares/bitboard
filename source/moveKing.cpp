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

/// @file   moveKing.cpp
/// @author de-Manzanares
/// @brief  Calculates all possible moves for a given king
///         and checks if the target square is in the range.

#include "bitBoards.h"

void calculateMovesCastling
        (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
bool squaresAreClear(vector<int> squares, ChessBoard& board);
bool rangeValidationKing(char pieceFrom, vector<int> range, int indexTo, ChessBoard& board);
bool castlingCheckCheck(char pieceFrom, vector<int> moves, ChessBoard& board);

bool moveKing(char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    if (pieceFrom=='K' || pieceFrom=='k') {

        vector<int> range;

        // Add available squares to the range
        calculateMovesDiagonal(pieceFrom, indexFrom, range, board);
        calculateMovesHorizontal(pieceFrom, indexFrom, range, board);
        calculateMovesCastling(pieceFrom, indexFrom, range, board);     // must come after horizontal
        calculateMovesVertical(pieceFrom, indexFrom, range, board);

        // Check if the target square is in the range
        // If the king is initiating a castling move, move the rook.
        if (rangeValidationKing(pieceFrom, range, indexTo, board)) {

            return true;
        }
        return false;
    }

    return false;
}

void calculateMovesCastling
        (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    // Castling squares
    const int QUEEN_SIDE = indexFrom+2;
    const int KING_SIDE = indexFrom-2;

    if (pieceFrom=='K' && !board.whiteKingMoved && !board.whiteQueenSideRookMoved
            && (squaresAreClear({indexFrom+1, QUEEN_SIDE}, board))
            && (castlingCheckCheck(pieceFrom, {indexFrom, indexFrom+1, QUEEN_SIDE}, board))) {
        range.push_back(QUEEN_SIDE);
    }
    if (pieceFrom=='K' && !board.whiteKingMoved && !board.whiteKingSideRookMoved
            && (squaresAreClear({indexFrom-1, KING_SIDE}, board))
            && (castlingCheckCheck(pieceFrom, {indexFrom, indexFrom-1, KING_SIDE}, board))) {
        range.push_back(KING_SIDE);
    }
    if (pieceFrom=='k' && !board.blackKingMoved && !board.blackQueenSideRookMoved
            && (squaresAreClear({indexFrom+1, QUEEN_SIDE}, board))
            && (castlingCheckCheck(pieceFrom, {indexFrom, indexFrom+1, QUEEN_SIDE}, board))) {
        range.push_back(QUEEN_SIDE);
    }
    if (pieceFrom=='k' && !board.blackKingMoved && !board.blackKingSideRookMoved
            && (squaresAreClear({indexFrom-1, KING_SIDE}, board))
            && (castlingCheckCheck(pieceFrom, {indexFrom, indexFrom-1, KING_SIDE}, board))) {
        range.push_back(KING_SIDE);
    }

}

bool squaresAreClear(vector<int> squares, ChessBoard& board)
{
    for (int i = 0; i<squares.size(); i++) {
        if (pieceSearch(squares[i], board)!='E')
            return false;
    }
    return true;
}

bool rangeValidationKing(char pieceFrom, vector<int> range, int indexTo, ChessBoard& board)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {

        bool whiteCastlingKingSide = (pieceFrom=='K' && (indexTo==1));
        bool whiteCastlingQueenSide = (pieceFrom=='K' && (indexTo==5));
        bool blackCastlingKingSide = (pieceFrom=='k' && (indexTo==57));
        bool blackCastlingQueenSide = (pieceFrom=='k' && (indexTo==61));

        if (pieceFrom=='K') {
            board.whiteKingMoved = true;
        }
        if (pieceFrom=='k') {
            board.blackKingMoved = true;
        }
        if (whiteCastlingKingSide) {
            movePiece('R', 0, 2, board);
            board.whiteKingSideRookMoved = true;
        }
        if (whiteCastlingQueenSide) {
            movePiece('R', 7, 4, board);
            board.whiteQueenSideRookMoved = true;
        }
        if (blackCastlingKingSide) {
            movePiece('r', 56, 58, board);
            board.blackKingSideRookMoved = true;
        }
        if (blackCastlingQueenSide) {
            movePiece('r', 63, 60, board);
            board.blackQueenSideRookMoved = true;
        }
        return true;
    }
    else {
        return false;
    }
}

bool castlingCheckCheck(char pieceFrom, vector<int> moves, ChessBoard& board)
{
    vector<int> enemyRange;

    if (pieceFrom=='K') {
        enemyRange = sideInfluence('b', board);
        if (find_first_of(moves.begin(), moves.end(), enemyRange.begin(), enemyRange.end())!=moves.end()) {
            return false;
        }
    }
    if (pieceFrom=='k') {
        enemyRange = sideInfluence('w', board);
        if (find_first_of(moves.begin(), moves.end(), enemyRange.begin(), enemyRange.end())!=moves.end()) {
            return false;
        }
    }
    return true;
}

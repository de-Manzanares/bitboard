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

//----------------------------------------------------------------------------------------------------------------------
//  Checks if a given king move is legal.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks if a given king move is legal.
///
/// Use `calculateMovesDiagonal()`, `calculateMovesHorizontal()`, `calculateMovesCastling()`, and
/// `calculateMovesVertical()` to populate a vector with all possible moves for the king, then check if the target
/// square is in the range. `rangeValidationKing()` contains logic for castling.
///
/// @param pieceFrom To verify that the piece is a king.
/// @param indexFrom The starting position of the king.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the move is legal. <br>
///         False - the move is illegal.

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

//----------------------------------------------------------------------------------------------------------------------
//  Calculate castling moves for a given king.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Calculate castling moves for a given king.
///
/// Checks castling conditions for each king for each side:
/// - Has the king or rook moved?
/// - Are the squares between the king and rook unoccupied?
/// - Is the king in check?
/// - Would the king pass through or into check?
///
/// @post vector `range` is populated with castling moves.
///
/// @param pieceFrom To determine side; white or black.
/// @param indexFrom The starting position of the king.
/// @param range The vector to populate with legal moves.
/// @param board The chess board.

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

//----------------------------------------------------------------------------------------------------------------------
//  Check if the squares between the king and rook are unoccupied.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Check if the squares between the king and rook are unoccupied.
///
/// Use `pieceSearch()` to check each square for occupancy.
///
///
/// @param squares The squares between the king and rook.
/// @param board The chess board.
///
/// @return True - the squares are unoccupied. <br>
///        False - the squares are occupied.

bool squaresAreClear(vector<int> squares, ChessBoard& board)
{
    for (int i = 0; i<squares.size(); i++) {
        if (pieceSearch(squares[i], board)!='E')
            return false;
    }
    return true;
}

//----------------------------------------------------------------------------------------------------------------------
//  Checks if the target square is in the range. Move the rook if the king is initiating a castling move.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks if the target square is in the range. Move the rook if the king is initiating a castling move.
///
/// Check if the target square is in the range. Flag the king as moved, and move and flag the rook as moved if the king
/// is castling.
///
/// @post The `board` may be modified; if the king is initiating a castling move, move the rook.
///
/// @param pieceFrom Identify the king to check castling status.
/// @param range The vector containing all possible moves for the king.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the target square is in the range. <br>
///         False - the target square is not in the range.

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

//----------------------------------------------------------------------------------------------------------------------
//  Check if the is in check, or would pass through or into check.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Check if the is in check, or would pass through or into check.
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @param pieceFrom To determine side; white or black.
/// @param moves The list of squares to check for check.
/// @param board The chess board.
///
/// @return True - the king is not in check, and would not pass through or into check. <br>
///         False - the king is in check, or would pass through or into check.

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

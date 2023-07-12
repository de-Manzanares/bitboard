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
        (char pieceFrom, int indexFrom, vector<int>& range, CastlingRights& castlingRights,
                ChessBoard& board);
bool squaresAreClear(vector<int> squares, ChessBoard& board);
bool rangeValidationKing(char pieceFrom, vector<int> range, int indexTo, CastlingRights& castlingRights,
        ChessBoard& board);

bool moveKing(char pieceFrom, int indexFrom, int indexTo, CastlingRights& castlingRights, ChessBoard& board)
{
    if (pieceFrom=='K' || pieceFrom=='k') {

        vector<int> range;

        // Add available squares to the range
        calculateMovesDiagonal(pieceFrom, indexFrom, range, board);
        calculateMovesHorizontal(pieceFrom, indexFrom, range, board);
        calculateMovesCastling(pieceFrom, indexFrom, range, castlingRights, board);     // must come after horizontal
        calculateMovesVertical(pieceFrom, indexFrom, range, board);

        // Print the range
        printVector(range);

        // Check if the target square is in the range
        // If the king is initiating a castling move, move the rook.
        if (rangeValidationKing(pieceFrom, range, indexTo, castlingRights, board)) {

            return true;
        }
        return false;
    }

    return false;
}

void calculateMovesCastling
        (char pieceFrom, int indexFrom, vector<int>& range, CastlingRights& castlingRights,
                ChessBoard& board)
{
    // Castling squares
    const int QUEEN_SIDE = indexFrom+2;
    const int KING_SIDE = indexFrom-2;

    if (pieceFrom=='K' && !castlingRights.whiteKingMoved && !castlingRights.whiteQueenSideRookMoved
            && squaresAreClear({indexFrom+1, QUEEN_SIDE}, board)) {
        range.push_back(QUEEN_SIDE);
    }
    if (pieceFrom=='K' && !castlingRights.whiteKingMoved && !castlingRights.whiteKingSideRookMoved
            && squaresAreClear({indexFrom-1, KING_SIDE}, board)) {
        range.push_back(KING_SIDE);
    }
    if (pieceFrom=='k' && !castlingRights.blackKingMoved && !castlingRights.blackQueenSideRookMoved
            && squaresAreClear({indexFrom+1, QUEEN_SIDE}, board)) {
        range.push_back(QUEEN_SIDE);
    }
    if (pieceFrom=='k' && !castlingRights.blackKingMoved && !castlingRights.blackKingSideRookMoved
            && squaresAreClear({indexFrom-1, KING_SIDE}, board)) {
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

bool rangeValidationKing(char pieceFrom, vector<int> range, int indexTo, CastlingRights& castlingRights,
        ChessBoard& board)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {

        bool whiteCastlingKingSide = (pieceFrom=='K' && (indexTo==1));
        bool whiteCastlingQueenSide = (pieceFrom=='K' && (indexTo==5));
        bool blackCastlingKingSide = (pieceFrom=='k' && (indexTo==57));
        bool blackCastlingQueenSide = (pieceFrom=='k' && (indexTo==61));

        if (pieceFrom=='K') {
            castlingRights.whiteKingMoved = true;
            cout << "White king moved" << endl;
        }
        if (pieceFrom=='k') {
            castlingRights.blackKingMoved = true;
        }
        if (whiteCastlingKingSide) {
            movePiece('R', 0, 2, board);
            castlingRights.whiteKingSideRookMoved = true;
        }
        if (whiteCastlingQueenSide) {
            movePiece('R', 7, 4, board);
            castlingRights.whiteQueenSideRookMoved = true;
        }
        if (blackCastlingKingSide) {
            movePiece('r', 56, 58, board);
            castlingRights.blackKingSideRookMoved = true;
        }
        if (blackCastlingQueenSide) {
            movePiece('r', 63, 60, board);
            castlingRights.blackQueenSideRookMoved = true;
        }
        return true;
    }
    else {
        return false;
    }
}

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

/// @file   moveRook.cpp
/// @author de-Manzanares
/// @brief  Calculates all possible moves for a given rook,
///         and checks if the target square is in the range.

#include "bitBoards.h"

bool rangeValidationRook(char pieceFrom, int indexFrom, vector<int> range, int indexTo, CastlingRights& castlingRights);

bool moveRook(char pieceFrom, int indexFrom, int indexTo, CastlingRights& castlingRights, ChessBoard& board)
{
    if (pieceFrom=='R' || pieceFrom=='r') {

        vector<int> range;

        calculateMovesHorizontal(pieceFrom, indexFrom, range, board);
        calculateMovesVertical(pieceFrom, indexFrom, range, board);

        printVector(range);

        if (rangeValidationRook(pieceFrom, indexFrom, range, indexTo, castlingRights))
            return true;
        return false;
    }
    return false;
}

bool rangeValidationRook(char pieceFrom, int indexFrom, vector<int> range, int indexTo, CastlingRights& castlingRights)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {
        if (pieceFrom=='R') {
            if (indexFrom==0) {
                castlingRights.whiteKingSideRookMoved = true;
            }
            if (indexFrom==7) {
                castlingRights.whiteQueenSideRookMoved = true;
            }
        }
        else {
            if (indexFrom==56) {
                castlingRights.blackKingSideRookMoved = true;
            }
            if (indexFrom==63) {
                castlingRights.blackQueenSideRookMoved = true;
            }
        }

        return true;
    }
    else {
        return false;
    }
}

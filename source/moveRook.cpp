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

bool rangeValidationRook(char pieceFrom, int indexFrom, vector<int> range, int indexTo, ChessBoard& board);

bool rangeValidationRook(char pieceFrom, int indexFrom, vector<int> range, int indexTo, ChessBoard& board)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {
        if (pieceFrom=='R') {
            if (indexFrom==0) {
                board.whiteKingSideRookMoved = true;
            }
            if (indexFrom==7) {
                board.whiteQueenSideRookMoved = true;
            }
        }
        else {
            if (indexFrom==56) {
                board.blackKingSideRookMoved = true;
            }
            if (indexFrom==63) {
                board.blackQueenSideRookMoved = true;
            }
        }

        return true;
    }
    else {
        return false;
    }
}

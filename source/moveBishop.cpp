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

/// @file   moveBishop.cpp
/// @author de-Manzanares
/// @brief  Calculates all possible moves for a given bishop,
///         and checks if the target square is in the range.

#include "bitBoards.h"

bool moveBishop(char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    if (pieceFrom=='B' || pieceFrom=='b') {

        vector<int> range;

        calculateMovesDiagonal(pieceFrom, indexFrom, range, board);

        printCoordinates(range);

        if (rangeValidation(range, indexTo))
            return true;
        return false;
    }

    return false;
}

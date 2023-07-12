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

/// @file   calculateMovesHelper.cpp
/// @author de-Manzanares
/// @brief  Helper function for calculating moves for sliding pieces.

#include "bitBoards.h"

void calculateMovesHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board)
{
    std::vector<int> result;    // To store the indices of the squares that can be moved to.
    flag = 1;                   // To flag a square as empty, occupied by an enemy, or occupied by an ally.
    canMove = 1;                // To tell `squareSearch()` whether to continue searching for moves.

    // The `limit` puts a stopper on the sliding search
    // e.g. we don't need to search left if the piece is on the left edge of the board.
    for (int i = 0; i<limit; i++) {
        result = squareSearch(pieceFrom, flag, canMove, moves[i], board);
        if (result[1])
            range.push_back(moves[i]);
    }
}

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

/// @file   calculateMovesVertical.cpp
/// @author de-Manzanares
/// @brief  Calculates all available vertical from a given square.

#include "bitBoards.h"

void calculateMovesVerticalHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board);

void calculateMovesVertical(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    const int F_ONE = indexFrom+8*1;
    const int F_TWO = indexFrom+8*2;
    const int F_THREE = indexFrom+8*3;
    const int F_FOUR = indexFrom+8*4;
    const int F_FIVE = indexFrom+8*5;
    const int F_SIX = indexFrom+8*6;
    const int F_SEVEN = indexFrom+8*7;
    const int B_ONE = indexFrom-8*1;
    const int B_TWO = indexFrom-8*2;
    const int B_THREE = indexFrom-8*3;
    const int B_FOUR = indexFrom-8*4;
    const int B_FIVE = indexFrom-8*5;
    const int B_SIX = indexFrom-8*6;
    const int B_SEVEN = indexFrom-8*7;

    int topLimit;
    int bottomLimit;
    int rankFrom;
    int flag = 1;
    int canMove = 1;
    vector<int> result;

    rankFrom = indexFrom/8+1;
    topLimit = 8-rankFrom;
    bottomLimit = rankFrom-1;

    calculateMovesVerticalHelper(pieceFrom, range, flag, canMove,
            {F_ONE, F_TWO, F_THREE, F_FOUR, F_FIVE, F_SIX, F_SEVEN}, topLimit, board);
    calculateMovesVerticalHelper(pieceFrom, range, flag, canMove,
            {B_ONE, B_TWO, B_THREE, B_FOUR, B_FIVE, B_SIX, B_SEVEN}, bottomLimit, board);
}

void calculateMovesVerticalHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board)
{
    std::vector<int> result;
    flag = 1;
    canMove = 1;
    for (int i = 0; i<limit; i++) {
        result = squareSearch(pieceFrom, flag, canMove, moves[i], board);
        if (result[1])
            range.push_back(moves[i]);
    }
}

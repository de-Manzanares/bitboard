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

/// @file   calculateMovesDiagonal.cpp
/// @author de-Manzanares
/// @brief  Calculates all available diagonal moves from a given square.

#include "bitBoards.h"

void calculateMovesDiagonalHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board);

void calculateMovesDiagonal(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    if (pieceFrom!='K' && pieceFrom!='k') {
        const int FDL_ONE = indexFrom+9*1;
        const int FDL_TWO = indexFrom+9*2;
        const int FDL_THREE = indexFrom+9*3;
        const int FDL_FOUR = indexFrom+9*4;
        const int FDL_FIVE = indexFrom+9*5;
        const int FDL_SIX = indexFrom+9*6;
        const int FDL_SEVEN = indexFrom+9*7;

        const int FDR_ONE = indexFrom+7*1;
        const int FDR_TWO = indexFrom+7*2;
        const int FDR_THREE = indexFrom+7*3;
        const int FDR_FOUR = indexFrom+7*4;
        const int FDR_FIVE = indexFrom+7*5;
        const int FDR_SIX = indexFrom+7*6;
        const int FDR_SEVEN = indexFrom+7*7;

        const int BDL_ONE = indexFrom-7*1;
        const int BDL_TWO = indexFrom-7*2;
        const int BDL_THREE = indexFrom-7*3;
        const int BDL_FOUR = indexFrom-7*4;
        const int BDL_FIVE = indexFrom-7*5;
        const int BDL_SIX = indexFrom-7*6;
        const int BDL_SEVEN = indexFrom-7*7;

        const int BDR_ONE = indexFrom-9*1;
        const int BDR_TWO = indexFrom-9*2;
        const int BDR_THREE = indexFrom-9*3;
        const int BDR_FOUR = indexFrom-9*4;
        const int BDR_FIVE = indexFrom-9*5;
        const int BDR_SIX = indexFrom-9*6;
        const int BDR_SEVEN = indexFrom-9*7;

        int leftLimit;
        int rightLimit;
        char fileFrom;
        int flag = 1;
        int canMove = 1;
        vector<int> result;

        fileFrom = getFile(indexFrom);
        leftLimit = fileFrom-'a';
        rightLimit = 'h'-fileFrom;

        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove,
                {FDL_ONE, FDL_TWO, FDL_THREE, FDL_FOUR, FDL_FIVE, FDL_SIX, FDL_SEVEN}, leftLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove,
                {FDR_ONE, FDR_TWO, FDR_THREE, FDR_FOUR, FDR_FIVE, FDR_SIX, FDR_SEVEN}, rightLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove,
                {BDL_ONE, BDL_TWO, BDL_THREE, BDL_FOUR, BDL_FIVE, BDL_SIX, BDL_SEVEN}, leftLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove,
                {BDR_ONE, BDR_TWO, BDR_THREE, BDR_FOUR, BDR_FIVE, BDR_SIX, BDR_SEVEN}, rightLimit, board);
    }

    else {
        const int FDL_ONE = indexFrom+9*1;
        const int FDR_ONE = indexFrom+7*1;
        const int BDL_ONE = indexFrom-7*1;
        const int BDR_ONE = indexFrom-9*1;

        int leftLimit;
        int rightLimit;
        char fileFrom;
        int flag = 1;
        int canMove = 1;
        vector<int> result;

        fileFrom = getFile(indexFrom);
        if (fileFrom-'a'>0) {
            leftLimit = 1;
        }
        else {
            leftLimit = 0;
        }
        if ('h'-fileFrom>0) {
            rightLimit = 1;
        }
        else {
            rightLimit = 0;
        }

        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove, {FDL_ONE}, leftLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove, {FDR_ONE}, rightLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove, {BDL_ONE}, leftLimit, board);
        calculateMovesDiagonalHelper(pieceFrom, range, flag, canMove, {BDR_ONE}, rightLimit, board);
    }
}

void calculateMovesDiagonalHelper
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

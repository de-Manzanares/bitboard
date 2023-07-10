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

/// @file   calculateMovesHorizontal.cpp
/// @author de-Manzanares
/// @brief  Calculates all available horizontal moves from a given square.

#include "bitBoards.h"

void calculateMovesHorizontalHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board);

void calculateMovesHorizontal(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    if (pieceFrom!='K' && pieceFrom!='k') {
        const int L_ONE = indexFrom+1;
        const int L_TWO = indexFrom+2;
        const int L_THREE = indexFrom+3;
        const int L_FOUR = indexFrom+4;
        const int L_FIVE = indexFrom+5;
        const int L_SIX = indexFrom+6;
        const int L_SEVEN = indexFrom+7;
        const int R_ONE = indexFrom-1;
        const int R_TWO = indexFrom-2;
        const int R_THREE = indexFrom-3;
        const int R_FOUR = indexFrom-4;
        const int R_FIVE = indexFrom-5;
        const int R_SIX = indexFrom-6;
        const int R_SEVEN = indexFrom-7;

        int leftLimit;
        int rightLimit;
        char fileFrom;
        int flag = 1;
        int canMove = 1;
        vector<int> result;

        fileFrom = getFile(indexFrom);
        leftLimit = fileFrom-'a';
        rightLimit = 'h'-fileFrom;

        calculateMovesHorizontalHelper(pieceFrom, range, flag, canMove,
                {L_ONE, L_TWO, L_THREE, L_FOUR, L_FIVE, L_SIX, L_SEVEN}, leftLimit, board);
        calculateMovesHorizontalHelper(pieceFrom, range, flag, canMove,
                {R_ONE, R_TWO, R_THREE, R_FOUR, R_FIVE, R_SIX, R_SEVEN}, rightLimit, board);
    }

    else {
        const int L_ONE = indexFrom+1;
        const int R_ONE = indexFrom-1;

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

        calculateMovesHorizontalHelper(pieceFrom, range, flag, canMove, {L_ONE}, leftLimit, board);
        calculateMovesHorizontalHelper(pieceFrom, range, flag, canMove, {R_ONE}, rightLimit, board);
    }
}

void calculateMovesHorizontalHelper
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

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

/// @file   calculateMovesSliding.cpp
/// @author de-Manzanares
/// @brief  Contains functions to help calculate possible moves for sliding pieces.

#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
// Calculates all possible DIAGONAL moves for a given piece.
//----------------------------------------------------------------------------------------------------------------------
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

        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {FDL_ONE, FDL_TWO, FDL_THREE, FDL_FOUR, FDL_FIVE, FDL_SIX, FDL_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {FDR_ONE, FDR_TWO, FDR_THREE, FDR_FOUR, FDR_FIVE, FDR_SIX, FDR_SEVEN}, rightLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {BDL_ONE, BDL_TWO, BDL_THREE, BDL_FOUR, BDL_FIVE, BDL_SIX, BDL_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {BDR_ONE, BDR_TWO, BDR_THREE, BDR_FOUR, BDR_FIVE, BDR_SIX, BDR_SEVEN}, rightLimit, board);

        cleanRange(range);
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

        calculateMovesHelper(pieceFrom, range, flag, canMove, {FDL_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {FDR_ONE}, rightLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {BDL_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {BDR_ONE}, rightLimit, board);

        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Calculates all possible HORIZONTAL moves for a given piece.
//----------------------------------------------------------------------------------------------------------------------
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

        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {L_ONE, L_TWO, L_THREE, L_FOUR, L_FIVE, L_SIX, L_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {R_ONE, R_TWO, R_THREE, R_FOUR, R_FIVE, R_SIX, R_SEVEN}, rightLimit, board);

        cleanRange(range);
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

        calculateMovesHelper(pieceFrom, range, flag, canMove, {L_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {R_ONE}, rightLimit, board);

        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Calculates all possible VERTICAL moves for a given piece.
//----------------------------------------------------------------------------------------------------------------------
void calculateMovesVertical(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    if (pieceFrom!='K' && pieceFrom!='k') {
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

        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {F_ONE, F_TWO, F_THREE, F_FOUR, F_FIVE, F_SIX, F_SEVEN}, topLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {B_ONE, B_TWO, B_THREE, B_FOUR, B_FIVE, B_SIX, B_SEVEN}, bottomLimit, board);

        cleanRange(range);
    }

    else {
        const int F_ONE = indexFrom+8*1;
        const int B_ONE = indexFrom-8*1;

        int topLimit;
        int bottomLimit;
        int rankFrom;
        int flag = 1;
        int canMove = 1;
        vector<int> result;

        rankFrom = indexFrom/8+1;
        if (8-rankFrom>0) {
            topLimit = 1;
        }
        else {
            topLimit = 0;
        }
        if (rankFrom-1>0) {
            bottomLimit = 1;
        }
        else {
            bottomLimit = 0;
        }

        calculateMovesHelper(pieceFrom, range, flag, canMove, {F_ONE}, topLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {B_ONE}, bottomLimit, board);

        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Helper function for calculating sliding moves
//----------------------------------------------------------------------------------------------------------------------

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

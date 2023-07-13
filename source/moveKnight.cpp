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

/// @file   moveKnight.cpp
/// @author de-Manzanares
/// @brief  Calculates all possible moves for a given knight,
///         and checks if the target square is in the range.

#include "bitBoards.h"

void calculateMovesKnightHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board);

// Boolean function to check if the target square is in the range.
bool moveKnight(char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    const int ForwardLeft = indexFrom+17;
    const int ForwardRight = indexFrom+15;
    const int LeftForward = indexFrom+10;
    const int RightForward = indexFrom+6;
    const int LeftBack = indexFrom-6;
    const int RightBack = indexFrom-10;
    const int BackLeft = indexFrom-15;
    const int BackRight = indexFrom-17;

    std::vector<int> result;
    std::vector<int> range;

    int flag = 1;
    int canMove = 1;
    int limit = 2;
    vector<int> moves;

    // For reference
    // a8 through h1 is 63 through 0
    // {a8, b8, g8, h8, a7, b7, g7, h7, a2, b2, g2, h2, a1, b1, g1, h1}
    // {63, 62, 57, 56, 55, 54, 49, 48, 15, 14,  9,  8,  7,  6,  1,  0}

    switch (indexFrom) {
    case 63:moves = {BackRight, RightBack};
        break;
    case 62:moves = {BackRight, RightBack, BackLeft};
        break;
    case 57:moves = {BackRight, BackLeft, LeftBack};
        break;
    case 56:moves = {BackLeft, LeftBack};
        break;
    case 55:moves = {BackRight, RightBack, RightForward};
        break;
    case 54:moves = {BackRight, RightBack, RightForward, BackLeft};
        break;
    case 49:moves = {BackRight, BackLeft, LeftBack, LeftForward};
        break;
    case 48:moves = {BackLeft, LeftBack, LeftForward};
        break;
    case 15:moves = {RightBack, RightForward, ForwardRight};
        break;
    case 14:moves = {RightBack, RightForward, ForwardRight, ForwardLeft};
        break;
    case 9:moves = {LeftBack, LeftForward, ForwardLeft, ForwardRight};
        break;
    case 8:moves = {LeftBack, LeftForward, ForwardLeft};
        break;
    case 7:moves = {RightForward, ForwardRight};
        break;
    case 6:moves = {RightForward, ForwardRight, ForwardLeft};
        break;
    case 1:moves = {LeftForward, ForwardLeft, ForwardRight};
        break;
    case 0:moves = {LeftForward, ForwardLeft};
        break;
    default:moves = {BackRight, RightBack, BackLeft, LeftBack, RightForward, ForwardRight, LeftForward, ForwardLeft};
    }

    calculateMovesKnightHelper(pieceFrom, range, flag, canMove, moves, limit, board);

    printCoordinates(range);

    if (rangeValidation(range, indexTo))
        return true;
    return false;
}

void calculateMovesKnightHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board)
{
    std::vector<int> result;

    limit = moves.size();
    for (int i = 0; i<limit; i++) {
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, moves[i], board);
        if (result[1])
            range.push_back(moves[i]);
    }
}

// Calculates all possible moves for a given knight.
void calculateMoveKnight(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{
    const int ForwardLeft = indexFrom+17;
    const int ForwardRight = indexFrom+15;
    const int LeftForward = indexFrom+10;
    const int RightForward = indexFrom+6;
    const int LeftBack = indexFrom-6;
    const int RightBack = indexFrom-10;
    const int BackLeft = indexFrom-15;
    const int BackRight = indexFrom-17;

    std::vector<int> result;

    int flag = 1;
    int canMove = 1;
    int limit = 0;
    vector<int> moves;

    // For reference
    // a8 through h1 is 63 through 0
    // {a8, b8, g8, h8, a7, b7, g7, h7, a2, b2, g2, h2, a1, b1, g1, h1}
    // {63, 62, 57, 56, 55, 54, 49, 48, 15, 14,  9,  8,  7,  6,  1,  0}

    switch (indexFrom) {
    case 63:moves = {BackRight, RightBack};
        break;
    case 62:moves = {BackRight, RightBack, BackLeft};
        break;
    case 57:moves = {BackRight, BackLeft, LeftBack};
        break;
    case 56:moves = {BackLeft, LeftBack};
        break;
    case 55:moves = {BackRight, RightBack, RightForward};
        break;
    case 54:moves = {BackRight, RightBack, RightForward, BackLeft};
        break;
    case 49:moves = {BackRight, BackLeft, LeftBack, LeftForward};
        break;
    case 48:moves = {BackLeft, LeftBack, LeftForward};
        break;
    case 15:moves = {RightBack, RightForward, ForwardRight};
        break;
    case 14:moves = {RightBack, RightForward, ForwardRight, ForwardLeft};
        break;
    case 9:moves = {LeftBack, LeftForward, ForwardLeft, ForwardRight};
        break;
    case 8:moves = {LeftBack, LeftForward, ForwardLeft};
        break;
    case 7:moves = {RightForward, ForwardRight};
        break;
    case 6:moves = {RightForward, ForwardRight, ForwardLeft};
        break;
    case 1:moves = {LeftForward, ForwardLeft, ForwardRight};
        break;
    case 0:moves = {LeftForward, ForwardLeft};
        break;
    default:moves = {BackRight, RightBack, BackLeft, LeftBack, RightForward, ForwardRight, LeftForward, ForwardLeft};
    }

    calculateMovesKnightHelper(pieceFrom, range, flag, canMove, moves, limit, board);
}

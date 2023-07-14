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

/// @file   sideInfluence.cpp
/// @author de-Manzanares
/// @brief  Calculates squares under enemy influence.

#include "bitBoards.h"

void pawnInfluence(char pieceFrom, int indexFrom, vector<int>& range);

vector<int> sideInfluence(char side, ChessBoard& board)
{
    char pieceFrom;
    vector<int> range;

    for (int i = 63; i>=0; i--) {
        uint64_t mask = static_cast<uint64_t>(1) << i;
        if (side=='b') {
            if (board.black_pieces & mask) {
                pieceFrom = pieceSearch(i, board);
                pawnInfluence(pieceFrom, i, range);
                calculateMoveKnight(pieceFrom, i, range, board);
                calculateRange(pieceFrom, i, range, board);         // Queen, Rook, Bishop, King
            }
        }
        if (side=='w') {
            if (board.white_pieces & mask) {
                pieceFrom = pieceSearch(i, board);
                pawnInfluence(pieceFrom, i, range);
                calculateMoveKnight(pieceFrom, i, range, board);
                calculateRange(pieceFrom, i, range, board);         // Queen, Rook, Bishop, King
            }
        }
    }
    printCoordinates(range);
    cout << endl;
    return range;
}

void pawnInfluence(char pieceFrom, int indexFrom, vector<int>& range)
{
    if (pieceFrom=='p') {
        const int D_LEFT_ONE = indexFrom-9;
        const int D_RIGHT_ONE = indexFrom-7;
        if (getFile(indexFrom)!='h') {
            range.push_back(D_LEFT_ONE);
        }
        if (getFile(indexFrom)!='a') {
            range.push_back(D_RIGHT_ONE);
        }
    }
    if (pieceFrom=='P') {
        const int D_LEFT_ONE = indexFrom+9;
        const int D_RIGHT_ONE = indexFrom+7;
        if (getFile(indexFrom)!='a') {
            range.push_back(D_LEFT_ONE);
        }
        if (getFile(indexFrom)!='h') {
            range.push_back(D_RIGHT_ONE);
        }
    }
}

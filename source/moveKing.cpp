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

#include "bitBoards.h"

bool moveKing (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    if (pieceFrom == 'K' || pieceFrom == 'k') {
        const int F_ONE = indexFrom + 8 * 1;
        const int B_ONE = indexFrom - 8 * 1;
        const int L_ONE = indexFrom + 1;
        const int R_ONE = indexFrom - 1;
        const int FDL_ONE = indexFrom + 9 * 1;
        const int FDR_ONE = indexFrom + 7 * 1;
        const int BDL_ONE = indexFrom - 7 * 1;
        const int BDR_ONE = indexFrom - 9 * 1;

        bool canMoveF_ONE;
        bool canMoveB_ONE;
        bool canMoveL_ONE;
        bool canMoveR_ONE;
        bool canMoveFDL_ONE;
        bool canMoveFDR_ONE;
        bool canMoveBDL_ONE;
        bool canMoveBDR_ONE;

        int flag = 1;
        int canMove = 1;

        std::vector<int> result;
        std::vector<int> range = {};

        result = squareSearch(pieceFrom, flag, canMove, F_ONE, board);
        canMoveF_ONE = result[1];
        if (canMoveF_ONE)   {range.push_back(F_ONE);}

        flag = 1;
        canMove = 1;

        result = squareSearch(pieceFrom, flag, canMove, B_ONE, board);
        canMoveB_ONE = result[1];
        if (canMoveB_ONE) {range.push_back(B_ONE);}
        flag = 1;
        canMove = 1;

        if (!(isInFile_A(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_ONE, board);
            canMoveFDL_ONE = result[1];
            if (canMoveFDL_ONE)   {range.push_back(FDL_ONE);}
        }

        flag = 1;
        canMove = 1;

        if (!(isInFile_A(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_ONE, board);
            canMoveBDL_ONE = result[1];
            if (canMoveBDL_ONE) { range.push_back(BDL_ONE); }
        }

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_ONE, board);
            canMoveFDR_ONE = result[1];
            if (canMoveFDR_ONE) { range.push_back(FDR_ONE); }
        }

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_ONE, board);
            canMoveBDR_ONE = result[1];
            if (canMoveBDR_ONE) { range.push_back(BDR_ONE); }
        }

        flag = 1;
        canMove = 1;

        if (!(isInFile_A(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_ONE, board);
            canMoveL_ONE = result[1];
            if (canMoveL_ONE) { range.push_back(L_ONE); }
        }

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_ONE, board);
            canMoveR_ONE = result[1];
            if (canMoveR_ONE) { range.push_back(R_ONE); }
        }

        if (rangeValidation(range, indexTo))
            return true;
        return false;
    }

    return false;
}
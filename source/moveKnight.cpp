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

bool moveKnight (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    const int ForwardLeft   = indexFrom + 17;
    const int ForwardRight  = indexFrom + 15;
    const int LeftForward   = indexFrom + 10;
    const int RightForward  = indexFrom + 6;
    const int LeftBack      = indexFrom - 6;
    const int RightBack     = indexFrom - 10;
    const int BackLeft      = indexFrom - 15;
    const int BackRight     = indexFrom - 17;

    bool RANK_8 = isInRank_8(indexFrom);
    bool RANK_7 = isInRank_7(indexFrom);
    bool RANK_2 = isInRank_2(indexFrom);
    bool RANK_1 = isInRank_1(indexFrom);
    bool FILE_A = isInFile_A(indexFrom);
    bool FILE_B = isInFile_B(indexFrom);
    bool FILE_G = isInFile_G(indexFrom);
    bool FILE_H = isInFile_H(indexFrom);

    bool canMoveForwardLeft;
    bool canMoveForwardRight;
    bool canMoveLeftForward;
    bool canMoveRightForward;
    bool canMoveLeftBack;
    bool canMoveRightBack;
    bool canMoveBackLeft;
    bool canMoveBackRight;

    int flag = 1;
    int canMove = 1;

    std::vector<int> result;
    std::vector<int> range = {};

    bool isIn4x4Center = (!FILE_A && !FILE_B && !FILE_H && !FILE_G
            && !RANK_8 && !RANK_7 && !RANK_2 && !RANK_1);
    bool isIn4x4CenterViolate_B = (!FILE_A && !FILE_H && !FILE_G
            && !RANK_8 && !RANK_7 && !RANK_2 && !RANK_1);

    if (isIn4x4Center) {
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, ForwardLeft, board);
        canMoveForwardLeft = result[1];
        if (canMoveForwardLeft)   {range.push_back(ForwardLeft);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, ForwardRight, board);
        canMoveForwardRight = result[1];
        if (canMoveForwardRight)   {range.push_back(ForwardRight);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, LeftForward, board);
        canMoveLeftForward = result[1];
        if (canMoveLeftForward)   {range.push_back(LeftForward);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, RightForward, board);
        canMoveRightForward = result[1];
        if (canMoveRightForward)   {range.push_back(RightForward);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, LeftBack, board);
        canMoveLeftBack = result[1];
        if (canMoveLeftBack)   {range.push_back(LeftBack);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, RightBack, board);
        canMoveRightBack = result[1];
        if (canMoveRightBack)   {range.push_back(RightBack);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, BackLeft, board);
        canMoveBackLeft = result[1];
        if (canMoveBackLeft)   {range.push_back(BackLeft);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, BackRight, board);
        canMoveBackRight = result[1];
        if (canMoveBackRight)   {range.push_back(BackRight);}
    }

    if (isIn4x4CenterViolate_B) {
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, ForwardLeft, board);
        canMoveForwardLeft = result[1];
        if (canMoveForwardLeft)   {range.push_back(ForwardLeft);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, ForwardRight, board);
        canMoveForwardRight = result[1];
        if (canMoveForwardRight)   {range.push_back(ForwardRight);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, RightForward, board);
        canMoveRightForward = result[1];
        if (canMoveRightForward)   {range.push_back(RightForward);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, RightBack, board);
        canMoveRightBack = result[1];
        if (canMoveRightBack)   {range.push_back(RightBack);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, BackLeft, board);
        canMoveBackLeft = result[1];
        if (canMoveBackLeft)   {range.push_back(BackLeft);}
        flag = 1;
        canMove = 1;
        result = squareSearch(pieceFrom, flag, canMove, BackRight, board);
        canMoveBackRight = result[1];
        if (canMoveBackRight)   {range.push_back(BackRight);}
    }

    if (rangeValidation(range, indexTo))
        return true;
    return false;
}
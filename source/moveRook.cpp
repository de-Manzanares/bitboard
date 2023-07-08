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

bool moveRook (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    if (pieceFrom == 'R' || pieceFrom == 'r') {
        const int F_ONE   = indexFrom + 8 * 1;
        const int F_TWO   = indexFrom + 8 * 2;
        const int F_THREE = indexFrom + 8 * 3;
        const int F_FOUR  = indexFrom + 8 * 4;
        const int F_FIVE  = indexFrom + 8 * 5;
        const int F_SIX   = indexFrom + 8 * 6;
        const int F_SEVEN = indexFrom + 8 * 7;
        const int B_ONE   = indexFrom - 8 * 1;
        const int B_TWO   = indexFrom - 8 * 2;
        const int B_THREE = indexFrom - 8 * 3;
        const int B_FOUR  = indexFrom - 8 * 4;
        const int B_FIVE  = indexFrom - 8 * 5;
        const int B_SIX   = indexFrom - 8 * 6;
        const int B_SEVEN = indexFrom - 8 * 7;

        const int L_ONE   = indexFrom + 1;
        const int L_TWO   = indexFrom + 2;
        const int L_THREE = indexFrom + 3;
        const int L_FOUR  = indexFrom + 4;
        const int L_FIVE  = indexFrom + 5;
        const int L_SIX   = indexFrom + 6;
        const int L_SEVEN = indexFrom + 7;
        const int R_ONE   = indexFrom - 1;
        const int R_TWO   = indexFrom - 2;
        const int R_THREE = indexFrom - 3;
        const int R_FOUR  = indexFrom - 4;
        const int R_FIVE  = indexFrom - 5;
        const int R_SIX   = indexFrom - 6;
        const int R_SEVEN = indexFrom - 7;

        bool canMoveF_ONE   ;
        bool canMoveF_TWO   ;
        bool canMoveF_THREE ;
        bool canMoveF_FOUR  ;
        bool canMoveF_FIVE  ;
        bool canMoveF_SIX   ;
        bool canMoveF_SEVEN ;
        bool canMoveB_ONE   ;
        bool canMoveB_TWO   ;
        bool canMoveB_THREE ;
        bool canMoveB_FOUR  ;
        bool canMoveB_FIVE  ;
        bool canMoveB_SIX   ;
        bool canMoveB_SEVEN ;
        bool canMoveL_ONE   ;
        bool canMoveL_TWO   ;
        bool canMoveL_THREE ;
        bool canMoveL_FOUR  ;
        bool canMoveL_FIVE  ;
        bool canMoveL_SIX   ;
        bool canMoveL_SEVEN ;
        bool canMoveR_ONE   ;
        bool canMoveR_TWO   ;
        bool canMoveR_THREE ;
        bool canMoveR_FOUR  ;
        bool canMoveR_FIVE  ;
        bool canMoveR_SIX   ;
        bool canMoveR_SEVEN ;

        int flag = 1;
        int canMove = 1;

        std::vector<int> result;
        std::vector<int> range = {};

        result = squareSearch(pieceFrom, flag, canMove, F_ONE, board);
        canMoveF_ONE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_TWO, board);
        canMoveF_TWO = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_THREE, board);
        canMoveF_THREE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_FOUR, board);
        canMoveF_FOUR = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_FIVE, board);
        canMoveF_FIVE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_SIX, board);
        canMoveF_SIX = result[1];
        result = squareSearch(pieceFrom, flag, canMove, F_SEVEN, board);
        canMoveF_SEVEN = result[1];

        if (canMoveF_ONE)   {range.push_back(F_ONE);}
        if (canMoveF_TWO)   {range.push_back(F_TWO);}
        if (canMoveF_THREE) {range.push_back(F_THREE);}
        if (canMoveF_FOUR)  {range.push_back(F_FOUR);}
        if (canMoveF_FIVE)  {range.push_back(F_FIVE);}
        if (canMoveF_SIX)   {range.push_back(F_SIX);}
        if (canMoveF_SEVEN) {range.push_back(F_SEVEN);}

        flag = 1;
        canMove = 1;

        result = squareSearch(pieceFrom, flag, canMove, B_ONE, board);
        canMoveB_ONE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_TWO, board);
        canMoveB_TWO = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_THREE, board);
        canMoveB_THREE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_FOUR, board);
        canMoveB_FOUR = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_FIVE, board);
        canMoveB_FIVE = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_SIX, board);
        canMoveB_SIX = result[1];
        result = squareSearch(pieceFrom, flag, canMove, B_SEVEN, board);
        canMoveB_SEVEN = result[1];

        if (canMoveB_ONE)   {range.push_back(B_ONE);}
        if (canMoveB_TWO)   {range.push_back(B_TWO);}
        if (canMoveB_THREE) {range.push_back(B_THREE);}
        if (canMoveB_FOUR)  {range.push_back(B_FOUR);}
        if (canMoveB_FIVE)  {range.push_back(B_FIVE);}
        if (canMoveB_SIX)   {range.push_back(B_SIX);}
        if (canMoveB_SEVEN) {range.push_back(B_SEVEN);}

        flag = 1;
        canMove = 1;

        if (!(isInFile_A(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_ONE, board);
            canMoveL_ONE = result[1];
            if (canMoveL_ONE)   {range.push_back(L_ONE);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_TWO, board);
            canMoveL_TWO = result[1];
            if (canMoveL_TWO)   {range.push_back(L_TWO);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_THREE, board);
            canMoveL_THREE = result[1];
            if (canMoveL_THREE) {range.push_back(L_THREE);}

        if (!(isInFile_D)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, L_FOUR, board);
            canMoveL_FOUR = result[1];
            if (canMoveL_FOUR)  {range.push_back(L_FOUR);}

        if (!(isInFile_E)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, L_FIVE, board);
            canMoveL_FIVE = result[1];
            if (canMoveL_FIVE)  {range.push_back(L_FIVE);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_SIX, board);
            canMoveL_SIX = result[1];
            if (canMoveL_SIX)   {range.push_back(L_SIX);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, L_SEVEN, board);
            canMoveL_SEVEN = result[1];
            if (canMoveL_SEVEN) {range.push_back(L_SEVEN);}
        }}}}}}}

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_ONE, board);
            canMoveR_ONE = result[1];
            if (canMoveR_ONE)   {range.push_back(R_ONE);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_TWO, board);
            canMoveR_TWO = result[1];
            if (canMoveR_TWO)   {range.push_back(R_TWO);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_THREE, board);
            canMoveR_THREE = result[1];
            if (canMoveR_THREE) {range.push_back(R_THREE);}

        if (!(isInFile_E(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_FOUR, board);
            canMoveR_FOUR = result[1];
            if (canMoveR_FOUR)  {range.push_back(R_FOUR);}

        if (!(isInFile_D(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_FIVE, board);
            canMoveR_FIVE = result[1];
            if (canMoveR_FIVE)  {range.push_back(R_FIVE);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_SIX, board);
            canMoveR_SIX = result[1];
            if (canMoveR_SIX)   {range.push_back(R_SIX);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, R_SEVEN, board);
            canMoveR_SEVEN = result[1];
            if (canMoveR_SEVEN) {range.push_back(R_SEVEN);}
        }}}}}}}

        if (rangeValidation(range, indexTo))
            return true;
        return false;
    }
    return false;
}

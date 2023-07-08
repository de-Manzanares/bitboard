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

bool moveQueen (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    if (pieceFrom == 'Q' || pieceFrom == 'q') {
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

        const int FDL_ONE   = indexFrom + 9 * 1;
        const int FDL_TWO   = indexFrom + 9 * 2;
        const int FDL_THREE = indexFrom + 9 * 3;
        const int FDL_FOUR  = indexFrom + 9 * 4;
        const int FDL_FIVE  = indexFrom + 9 * 5;
        const int FDL_SIX   = indexFrom + 9 * 6;
        const int FDL_SEVEN = indexFrom + 9 * 7;
        const int FDR_ONE   = indexFrom + 7 * 1;
        const int FDR_TWO   = indexFrom + 7 * 2;
        const int FDR_THREE = indexFrom + 7 * 3;
        const int FDR_FOUR  = indexFrom + 7 * 4;
        const int FDR_FIVE  = indexFrom + 7 * 5;
        const int FDR_SIX   = indexFrom + 7 * 6;
        const int FDR_SEVEN = indexFrom + 7 * 7;

        const int BDL_ONE   = indexFrom - 7 * 1;
        const int BDL_TWO   = indexFrom - 7 * 2;
        const int BDL_THREE = indexFrom - 7 * 3;
        const int BDL_FOUR  = indexFrom - 7 * 4;
        const int BDL_FIVE  = indexFrom - 7 * 5;
        const int BDL_SIX   = indexFrom - 7 * 6;
        const int BDL_SEVEN = indexFrom - 7 * 7;
        const int BDR_ONE   = indexFrom - 9 * 1;
        const int BDR_TWO   = indexFrom - 9 * 2;
        const int BDR_THREE = indexFrom - 9 * 3;
        const int BDR_FOUR  = indexFrom - 9 * 4;
        const int BDR_FIVE  = indexFrom - 9 * 5;
        const int BDR_SIX   = indexFrom - 9 * 6;
        const int BDR_SEVEN = indexFrom - 9 * 7;

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

        bool canMoveFDL_ONE  ;
        bool canMoveFDL_TWO  ;
        bool canMoveFDL_THREE;
        bool canMoveFDL_FOUR ;
        bool canMoveFDL_FIVE ;
        bool canMoveFDL_SIX  ;
        bool canMoveFDL_SEVEN;
        bool canMoveFDR_ONE  ;
        bool canMoveFDR_TWO  ;
        bool canMoveFDR_THREE;
        bool canMoveFDR_FOUR ;
        bool canMoveFDR_FIVE ;
        bool canMoveFDR_SIX  ;
        bool canMoveFDR_SEVEN;

        bool canMoveBDL_ONE  ;
        bool canMoveBDL_TWO  ;
        bool canMoveBDL_THREE;
        bool canMoveBDL_FOUR ;
        bool canMoveBDL_FIVE ;
        bool canMoveBDL_SIX  ;
        bool canMoveBDL_SEVEN;
        bool canMoveBDR_ONE  ;
        bool canMoveBDR_TWO  ;
        bool canMoveBDR_THREE;
        bool canMoveBDR_FOUR ;
        bool canMoveBDR_FIVE ;
        bool canMoveBDR_SIX  ;
        bool canMoveBDR_SEVEN;

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
            result = squareSearch(pieceFrom, flag, canMove, FDL_ONE, board);
            canMoveFDL_ONE = result[1];
            if (canMoveFDL_ONE)   {range.push_back(FDL_ONE);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_TWO, board);
            canMoveFDL_TWO = result[1];
            if (canMoveFDL_TWO)   {range.push_back(FDL_TWO);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_THREE, board);
            canMoveFDL_THREE = result[1];
            if (canMoveFDL_THREE) {range.push_back(FDL_THREE);}

        if (!(isInFile_D)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_FOUR, board);
            canMoveFDL_FOUR = result[1];
            if (canMoveFDL_FOUR)  {range.push_back(FDL_FOUR);}

        if (!(isInFile_E)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_FIVE, board);
            canMoveFDL_FIVE = result[1];
            if (canMoveFDL_FIVE)  {range.push_back(FDL_FIVE);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_SIX, board);
            canMoveFDL_SIX = result[1];
            if (canMoveFDL_SIX)   {range.push_back(FDL_SIX);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDL_SEVEN, board);
            canMoveFDL_SEVEN = result[1];
            if (canMoveFDL_SEVEN) {range.push_back(FDL_SEVEN);}
        }}}}}}}

        flag = 1;
        canMove = 1;

        if (!(isInFile_A(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_ONE, board);
            canMoveBDL_ONE = result[1];
            if (canMoveBDL_ONE)   {range.push_back(BDL_ONE);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_TWO, board);
            canMoveBDL_TWO = result[1];
            if (canMoveBDL_TWO)   {range.push_back(BDL_TWO);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_THREE, board);
            canMoveBDL_THREE = result[1];
            if (canMoveBDL_THREE) {range.push_back(BDL_THREE);}

        if (!(isInFile_D)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_FOUR, board);
            canMoveBDL_FOUR = result[1];
            if (canMoveBDL_FOUR)  {range.push_back(BDL_FOUR);}

        if (!(isInFile_E)(indexFrom)) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_FIVE, board);
            canMoveBDL_FIVE = result[1];
            if (canMoveBDL_FIVE)  {range.push_back(BDL_FIVE);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_SIX, board);
            canMoveBDL_SIX = result[1];
            if (canMoveBDL_SIX)   {range.push_back(BDL_SIX);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDL_SEVEN, board);
            canMoveBDL_SEVEN = result[1];
            if (canMoveBDL_SEVEN) {range.push_back(BDL_SEVEN);}
        }}}}}}}

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_ONE, board);
            canMoveFDR_ONE = result[1];
            if (canMoveFDR_ONE)   {range.push_back(FDR_ONE);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_TWO, board);
            canMoveFDR_TWO = result[1];
            if (canMoveFDR_TWO)   {range.push_back(FDR_TWO);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_THREE, board);
            canMoveFDR_THREE = result[1];
            if (canMoveFDR_THREE) {range.push_back(FDR_THREE);}

        if (!(isInFile_E(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_FOUR, board);
            canMoveFDR_FOUR = result[1];
            if (canMoveFDR_FOUR)  {range.push_back(FDR_FOUR);}

        if (!(isInFile_D(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_FIVE, board);
            canMoveFDR_FIVE = result[1];
            if (canMoveFDR_FIVE)  {range.push_back(FDR_FIVE);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_SIX, board);
            canMoveFDR_SIX = result[1];
            if (canMoveFDR_SIX)   {range.push_back(FDR_SIX);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, FDR_SEVEN, board);
            canMoveFDR_SEVEN = result[1];
            if (canMoveFDR_SEVEN) {range.push_back(FDR_SEVEN);}
        }}}}}}}

        flag = 1;
        canMove = 1;

        if (!(isInFile_H(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_ONE, board);
            canMoveBDR_ONE = result[1];
            if (canMoveBDR_ONE)   {range.push_back(BDR_ONE);}

        if (!(isInFile_G(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_TWO, board);
            canMoveBDR_TWO = result[1];
            if (canMoveBDR_TWO)   {range.push_back(BDR_TWO);}

        if (!(isInFile_F(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_THREE, board);
            canMoveBDR_THREE = result[1];
            if (canMoveBDR_THREE) {range.push_back(BDR_THREE);}

        if (!(isInFile_E(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_FOUR, board);
            canMoveBDR_FOUR = result[1];
            if (canMoveBDR_FOUR)  {range.push_back(BDR_FOUR);}

        if (!(isInFile_D(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_FIVE, board);
            canMoveBDR_FIVE = result[1];
            if (canMoveBDR_FIVE)  {range.push_back(BDR_FIVE);}

        if (!(isInFile_C(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_SIX, board);
            canMoveBDR_SIX = result[1];
            if (canMoveBDR_SIX)   {range.push_back(BDR_SIX);}

        if (!(isInFile_B(indexFrom))) {
            result = squareSearch(pieceFrom, flag, canMove, BDR_SEVEN, board);
            canMoveBDR_SEVEN = result[1];
            if (canMoveBDR_SEVEN) {range.push_back(BDR_SEVEN);}
        }}}}}}}

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
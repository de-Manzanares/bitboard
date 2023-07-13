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

/// @file   movePawn.cpp
/// @author de-Manzanares
/// @brief  Enforces the rules of movement for the pawn.

#include <vector>
#include "bitBoards.h"

// Boolean function that checks if the pawn can move to the target square.
bool movePawn(char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{

    if (pieceFrom=='p') {
        const int F_ONE = indexFrom-8;
        const int F_TWO = indexFrom-16;
        const int D_LEFT_ONE = indexFrom-9;
        const int D_RIGHT_ONE = indexFrom-7;
        uint64_t maskLeft = static_cast<uint64_t>(1) << D_LEFT_ONE;
        uint64_t maskRight = static_cast<uint64_t>(1) << D_RIGHT_ONE;
        uint64_t maskF_ONE = static_cast<uint64_t>(1) << F_ONE;
        uint64_t maskF_TWO = static_cast<uint64_t>(1) << F_TWO;

        bool canMoveF_ONE = (!(board.black_pawn & maskF_ONE)
                && !(board.black_night & maskF_ONE)
                && !(board.black_bishop & maskF_ONE)
                && !(board.black_rook & maskF_ONE)
                && !(board.black_queen & maskF_ONE)
                && !(board.black_king & maskF_ONE)
                && !(board.white_Pawn & maskF_ONE)
                && !(board.white_Night & maskF_ONE)
                && !(board.white_Bishop & maskF_ONE)
                && !(board.white_Rook & maskF_ONE)
                && !(board.white_Queen & maskF_ONE)
                && !(board.white_King & maskF_ONE));

        bool canMoveF_TWO = ((canMoveF_ONE)
                && (getRank(indexFrom)==7)
                && !(board.black_pawn & maskF_TWO)
                && !(board.black_night & maskF_TWO)
                && !(board.black_bishop & maskF_TWO)
                && !(board.black_rook & maskF_TWO)
                && !(board.black_queen & maskF_TWO)
                && !(board.black_king & maskF_TWO)
                && !(board.white_Pawn & maskF_TWO)
                && !(board.white_Night & maskF_TWO)
                && !(board.white_Bishop & maskF_TWO)
                && !(board.white_Rook & maskF_TWO)
                && !(board.white_Queen & maskF_TWO)
                && !(board.white_King & maskF_TWO));

        bool canCaptureLeft = ((getFile(indexFrom)!= 'h'))
                && ((board.white_Pawn & maskLeft)
                        || (board.white_Night & maskLeft)
                        || (board.white_Bishop & maskLeft)
                        || (board.white_Rook & maskLeft)
                        || (board.white_Queen & maskLeft)
                        || (board.white_King & maskLeft));

        bool canCaptureRight = (getFile(indexFrom)!= 'a')
                && ((board.white_Pawn & maskRight)
                        || (board.white_Night & maskRight)
                        || (board.white_Bishop & maskRight)
                        || (board.white_Rook & maskRight)
                        || (board.white_Queen & maskRight)
                        || (board.white_King & maskRight));

        std::vector<int> range = {};

        if (canMoveF_ONE) { range.push_back(F_ONE); }
        if (canMoveF_TWO) { range.push_back(F_TWO); }
        if (canCaptureLeft) { range.push_back(D_LEFT_ONE); }
        if (canCaptureRight) { range.push_back(D_RIGHT_ONE); }

        cleanRange(range);
        printCoordinates(range);

        if (rangeValidation(range, indexTo))
            return true;

        return false;
    }

    if (pieceFrom=='P') {
        const int F_ONE = indexFrom+8;
        const int F_TWO = indexFrom+16;
        const int D_LEFT_ONE = indexFrom+9;
        const int D_RIGHT_ONE = indexFrom+7;
        uint64_t maskLeft = static_cast<uint64_t>(1) << D_LEFT_ONE;
        uint64_t maskRight = static_cast<uint64_t>(1) << D_RIGHT_ONE;
        uint64_t maskF_ONE = static_cast<uint64_t>(1) << F_ONE;
        uint64_t maskF_TWO = static_cast<uint64_t>(1) << F_TWO;

        bool canMoveF_ONE = (!(board.black_pawn & maskF_ONE)
                && !(board.black_night & maskF_ONE)
                && !(board.black_bishop & maskF_ONE)
                && !(board.black_rook & maskF_ONE)
                && !(board.black_queen & maskF_ONE)
                && !(board.black_king & maskF_ONE)
                && !(board.white_Pawn & maskF_ONE)
                && !(board.white_Night & maskF_ONE)
                && !(board.white_Bishop & maskF_ONE)
                && !(board.white_Rook & maskF_ONE)
                && !(board.white_Queen & maskF_ONE)
                && !(board.white_King & maskF_ONE));

        bool canMoveF_TWO = ((canMoveF_ONE)
                && (getRank(indexFrom)==2)
                && !(board.black_pawn & maskF_TWO)
                && !(board.black_night & maskF_TWO)
                && !(board.black_bishop & maskF_TWO)
                && !(board.black_rook & maskF_TWO)
                && !(board.black_queen & maskF_TWO)
                && !(board.black_king & maskF_TWO)
                && !(board.white_Pawn & maskF_TWO)
                && !(board.white_Night & maskF_TWO)
                && !(board.white_Bishop & maskF_TWO)
                && !(board.white_Rook & maskF_TWO)
                && !(board.white_Queen & maskF_TWO)
                && !(board.white_King & maskF_TWO));

        bool canCaptureLeft = (getFile(indexFrom)!= 'a')
                && ((board.black_pawn & maskLeft)
                        || (board.black_night & maskLeft)
                        || (board.black_bishop & maskLeft)
                        || (board.black_rook & maskLeft)
                        || (board.black_queen & maskLeft)
                        || (board.black_king & maskLeft));

        bool canCaptureRight = (getFile(indexFrom)!= 'h')
                && ((board.black_pawn & maskRight)
                        || (board.black_night & maskRight)
                        || (board.black_bishop & maskRight)
                        || (board.black_rook & maskRight)
                        || (board.black_queen & maskRight)
                        || (board.black_king & maskRight));

        std::vector<int> range = {};

        if (canMoveF_ONE) { range.push_back(F_ONE); }
        if (canMoveF_TWO) { range.push_back(F_TWO); }
        if (canCaptureLeft) { range.push_back(D_LEFT_ONE); }
        if (canCaptureRight) { range.push_back(D_RIGHT_ONE); }

        cleanRange(range);
        printCoordinates(range);

        if (rangeValidation(range, indexTo))
            return true;

        return false;
    }
    return false;
}

// Calculates all possible moves for a given pawn.
void calculateMovePawn(char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board)
{

    if (pieceFrom=='p') {
        const int F_ONE = indexFrom-8;
        const int F_TWO = indexFrom-16;
        const int D_LEFT_ONE = indexFrom-9;
        const int D_RIGHT_ONE = indexFrom-7;

        uint64_t maskLeft = static_cast<uint64_t>(1) << D_LEFT_ONE;
        uint64_t maskRight = static_cast<uint64_t>(1) << D_RIGHT_ONE;
        uint64_t maskF_ONE = static_cast<uint64_t>(1) << F_ONE;
        uint64_t maskF_TWO = static_cast<uint64_t>(1) << F_TWO;

        bool canMoveF_ONE = (!(board.black_pawn & maskF_ONE)
                && !(board.black_night & maskF_ONE)
                && !(board.black_bishop & maskF_ONE)
                && !(board.black_rook & maskF_ONE)
                && !(board.black_queen & maskF_ONE)
                && !(board.black_king & maskF_ONE)
                && !(board.white_Pawn & maskF_ONE)
                && !(board.white_Night & maskF_ONE)
                && !(board.white_Bishop & maskF_ONE)
                && !(board.white_Rook & maskF_ONE)
                && !(board.white_Queen & maskF_ONE)
                && !(board.white_King & maskF_ONE));

        bool canMoveF_TWO = ((canMoveF_ONE)
                && (getRank(indexFrom)==7)
                && !(board.black_pawn & maskF_TWO)
                && !(board.black_night & maskF_TWO)
                && !(board.black_bishop & maskF_TWO)
                && !(board.black_rook & maskF_TWO)
                && !(board.black_queen & maskF_TWO)
                && !(board.black_king & maskF_TWO)
                && !(board.white_Pawn & maskF_TWO)
                && !(board.white_Night & maskF_TWO)
                && !(board.white_Bishop & maskF_TWO)
                && !(board.white_Rook & maskF_TWO)
                && !(board.white_Queen & maskF_TWO)
                && !(board.white_King & maskF_TWO));

        bool canCaptureLeft = (getFile(indexFrom)!= 'a')
                && ((board.white_Pawn & maskLeft)
                        || (board.white_Night & maskLeft)
                        || (board.white_Bishop & maskLeft)
                        || (board.white_Rook & maskLeft)
                        || (board.white_Queen & maskLeft)
                        || (board.white_King & maskLeft));

        bool canCaptureRight = (getFile(indexFrom)!= 'h')
                && ((board.white_Pawn & maskRight)
                        || (board.white_Night & maskRight)
                        || (board.white_Bishop & maskRight)
                        || (board.white_Rook & maskRight)
                        || (board.white_Queen & maskRight)
                        || (board.white_King & maskRight));

        if (canMoveF_ONE) { range.push_back(F_ONE); }
        if (canMoveF_TWO) { range.push_back(F_TWO); }
        if (canCaptureLeft) { range.push_back(D_LEFT_ONE); }
        if (canCaptureRight) { range.push_back(D_RIGHT_ONE); }

        cleanRange(range);
    }

    if (pieceFrom=='P') {
        const int F_ONE = indexFrom+8;
        const int F_TWO = indexFrom+16;
        const int D_LEFT_ONE = indexFrom+9;
        const int D_RIGHT_ONE = indexFrom+7;
        uint64_t maskLeft = static_cast<uint64_t>(1) << D_LEFT_ONE;
        uint64_t maskRight = static_cast<uint64_t>(1) << D_RIGHT_ONE;
        uint64_t maskF_ONE = static_cast<uint64_t>(1) << F_ONE;
        uint64_t maskF_TWO = static_cast<uint64_t>(1) << F_TWO;

        bool canMoveF_ONE = (!(board.black_pawn & maskF_ONE)
                && !(board.black_night & maskF_ONE)
                && !(board.black_bishop & maskF_ONE)
                && !(board.black_rook & maskF_ONE)
                && !(board.black_queen & maskF_ONE)
                && !(board.black_king & maskF_ONE)
                && !(board.white_Pawn & maskF_ONE)
                && !(board.white_Night & maskF_ONE)
                && !(board.white_Bishop & maskF_ONE)
                && !(board.white_Rook & maskF_ONE)
                && !(board.white_Queen & maskF_ONE)
                && !(board.white_King & maskF_ONE));

        bool canMoveF_TWO = ((canMoveF_ONE)
                && (getRank(indexFrom)==2)
                && !(board.black_pawn & maskF_TWO)
                && !(board.black_night & maskF_TWO)
                && !(board.black_bishop & maskF_TWO)
                && !(board.black_rook & maskF_TWO)
                && !(board.black_queen & maskF_TWO)
                && !(board.black_king & maskF_TWO)
                && !(board.white_Pawn & maskF_TWO)
                && !(board.white_Night & maskF_TWO)
                && !(board.white_Bishop & maskF_TWO)
                && !(board.white_Rook & maskF_TWO)
                && !(board.white_Queen & maskF_TWO)
                && !(board.white_King & maskF_TWO));

        bool canCaptureLeft = (getFile(indexFrom)!= 'a')
                && ((board.black_pawn & maskLeft)
                        || (board.black_night & maskLeft)
                        || (board.black_bishop & maskLeft)
                        || (board.black_rook & maskLeft)
                        || (board.black_queen & maskLeft)
                        || (board.black_king & maskLeft));

        bool canCaptureRight = (getFile(indexFrom)!= 'h')
                && ((board.black_pawn & maskRight)
                        || (board.black_night & maskRight)
                        || (board.black_bishop & maskRight)
                        || (board.black_rook & maskRight)
                        || (board.black_queen & maskRight)
                        || (board.black_king & maskRight));

        if (canMoveF_ONE) { range.push_back(F_ONE); }
        if (canMoveF_TWO) { range.push_back(F_TWO); }
        if (canCaptureLeft) { range.push_back(D_LEFT_ONE); }
        if (canCaptureRight) { range.push_back(D_RIGHT_ONE); }

        cleanRange(range);
    }
}
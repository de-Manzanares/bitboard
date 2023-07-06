#include <vector>
#include <algorithm>
#include "bitBoards.h"

bool rangeValidation(std::vector<int> range, int indexTo);

bool movePawn(char piece, int indexFrom, int indexTo, ChessBoard& board) {
    if (piece == 'P') {
        const int F_ONE = indexFrom + 8;
        const int F_TWO = indexFrom + 16;
        const int D_LEFT_ONE = indexFrom + 9;
        const int D_RIGHT_ONE = indexFrom + 7;
        uint64_t maskLeft = static_cast<uint64_t>(1) << D_LEFT_ONE;
        uint64_t maskRight = static_cast<uint64_t>(1) << D_RIGHT_ONE;
        uint64_t maskF_ONE = static_cast<uint64_t>(1) << F_ONE;
        uint64_t maskF_TWO = static_cast<uint64_t>(1) << F_TWO;

        bool canMoveF_ONE = (!( board.black_pawn    & maskF_ONE)
                          && !( board.black_night   & maskF_ONE)
                          && !( board.black_bishop  & maskF_ONE)
                          && !( board.black_rook    & maskF_ONE)
                          && !( board.black_queen   & maskF_ONE)
                          && !( board.black_king    & maskF_ONE)
                          && !( board.white_Pawn    & maskF_ONE)
                          && !( board.white_Night   & maskF_ONE)
                          && !( board.white_Bishop  & maskF_ONE)
                          && !( board.white_Rook    & maskF_ONE)
                          && !( board.white_Queen   & maskF_ONE)
                          && !( board.white_King    & maskF_ONE));

        bool canMoveF_TWO = ( (15 >= indexFrom && indexFrom >= 8)
                          && !( board.black_pawn    & maskF_TWO)
                          && !( board.black_night   & maskF_TWO)
                          && !( board.black_bishop  & maskF_TWO)
                          && !( board.black_rook    & maskF_TWO)
                          && !( board.black_queen   & maskF_TWO)
                          && !( board.black_king    & maskF_TWO)
                          && !( board.white_Pawn    & maskF_TWO)
                          && !( board.white_Night   & maskF_TWO)
                          && !( board.white_Bishop  & maskF_TWO)
                          && !( board.white_Rook    & maskF_TWO)
                          && !( board.white_Queen   & maskF_TWO)
                          && !( board.white_King    & maskF_TWO));


        bool canCaptureLeft = (( board.black_pawn    & maskLeft )
                            || ( board.black_night   & maskLeft )
                            || ( board.black_bishop  & maskLeft )
                            || ( board.black_rook    & maskLeft )
                            || ( board.black_queen   & maskLeft )
                            || ( board.black_king    & maskLeft ));

        bool canCaptureRight =   (( board.black_pawn    & maskRight )
                               || ( board.black_night   & maskRight )
                               || ( board.black_bishop  & maskRight )
                               || ( board.black_rook    & maskRight )
                               || ( board.black_queen   & maskRight )
                               || ( board.black_king    & maskRight ));

        std::vector<int> range = {};

        if (canMoveF_ONE) {range.push_back(F_ONE);}
        if (canMoveF_TWO) {range.push_back(F_TWO);}
        if (canCaptureLeft) {range.push_back(D_LEFT_ONE);}
        if (canCaptureRight) {range.push_back(D_RIGHT_ONE);}

        if (rangeValidation(range, indexTo))
            return true;

        return false;
    }
}

bool rangeValidation(std::vector<int> range, int indexTo)
{
    if(find(range.begin(), range.end(), indexTo) != range.end()) {
       return true;
    }
    else {
        return false;
    }
}
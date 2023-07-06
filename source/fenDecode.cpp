#include "bitBoards.h"
#include <string>

void fenDecode(string& fenIn, ChessBoard& board)
{
    int i = 0;
    int j = 63;

    board.black_pawn   = 0;
    board.black_night  = 0;
    board.black_bishop = 0;
    board.black_rook   = 0;
    board.black_queen  = 0;
    board.black_king   = 0;
    board.white_Pawn   = 0;
    board.white_Night  = 0;
    board.white_Bishop = 0;
    board.white_Rook   = 0;
    board.white_Queen  = 0;
    board.white_King   = 0;

    while (i < fenIn.size()) {
        if (fenIn[i] >= '1' && fenIn[i] <= '8') {
            j -= fenIn[i] - '0';
        } else if (fenIn[i] != '/') {
            addPiece(fenIn[i], j, board);
            j--;
        }
        i++;
    }
}
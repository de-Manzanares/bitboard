#include "bitBoards.h"

void subtractPiece(char piece, int index, ChessBoard& board)
{
    uint64_t mask = static_cast<uint64_t>(1) << index;

    if (piece == 'p') {board.black_pawn   = board.black_pawn   - mask;}
    if (piece == 'n') {board.black_night  = board.black_night  - mask;}
    if (piece == 'b') {board.black_bishop = board.black_bishop - mask;}
    if (piece == 'r') {board.black_rook   = board.black_rook   - mask;}
    if (piece == 'q') {board.black_queen  = board.black_queen  - mask;}
    if (piece == 'k') {board.black_king   = board.black_king   - mask;}
    if (piece == 'P') {board.white_Pawn   = board.white_Pawn   - mask;}
    if (piece == 'N') {board.white_Night  = board.white_Night  - mask;}
    if (piece == 'B') {board.white_Bishop = board.white_Bishop - mask;}
    if (piece == 'R') {board.white_Rook   = board.white_Rook   - mask;}
    if (piece == 'Q') {board.white_Queen  = board.white_Queen  - mask;}
    if (piece == 'K') {board.white_King   = board.white_King   - mask;}
}


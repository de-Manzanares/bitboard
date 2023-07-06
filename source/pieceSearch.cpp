#include "bitBoards.h"

char pieceSearch(int index, const ChessBoard& board)

{
    char piece = 'E';
    uint64_t mask = static_cast<uint64_t>(1) << index;

    if (board.black_pawn   & mask) { piece = 'p' ; return piece ;}
    if (board.black_night  & mask) { piece = 'n' ; return piece ;}
    if (board.black_bishop & mask) { piece = 'b' ; return piece ;}
    if (board.black_rook   & mask) { piece = 'r' ; return piece ;}
    if (board.black_queen  & mask) { piece = 'q' ; return piece ;}
    if (board.black_king   & mask) { piece = 'k' ; return piece ;}
    if (board.white_Pawn   & mask) { piece = 'P' ; return piece ;}
    if (board.white_Night  & mask) { piece = 'N' ; return piece ;}
    if (board.white_Bishop & mask) { piece = 'B' ; return piece ;}
    if (board.white_Rook   & mask) { piece = 'R' ; return piece ;}
    if (board.white_Queen  & mask) { piece = 'Q' ; return piece ;}
    if (board.white_King   & mask) { piece = 'K' ; return piece ;}

    return piece;
}
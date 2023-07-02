#include <cstdint>
#include "bitBoards.h"

char pieceSearch(int index, const ChessBoard& board)

{
    char piece = 'E';
    int found = 0;
    uint64_t mask = static_cast<uint64_t>(1) << index;

                     if (board.black_pawn   & mask) { piece = 'p' ; found = 1;}
    if (found == 0) {if (board.black_night  & mask) { piece = 'n' ; found = 1;}}
    if (found == 0) {if (board.black_bishop & mask) { piece = 'b' ; found = 1;}}
    if (found == 0) {if (board.black_rook   & mask) { piece = 'r' ; found = 1;}}
    if (found == 0) {if (board.black_queen  & mask) { piece = 'q' ; found = 1;}}
    if (found == 0) {if (board.black_king   & mask) { piece = 'k' ; found = 1;}}
    if (found == 0) {if (board.white_Pawn   & mask) { piece = 'P' ; found = 1;}}
    if (found == 0) {if (board.white_Night  & mask) { piece = 'N' ; found = 1;}}
    if (found == 0) {if (board.white_Bishop & mask) { piece = 'B' ; found = 1;}}
    if (found == 0) {if (board.white_Rook   & mask) { piece = 'R' ; found = 1;}}
    if (found == 0) {if (board.white_Queen  & mask) { piece = 'Q' ; found = 1;}}
    if (found == 0) {if (board.white_King   & mask) { piece = 'K' ; found = 1;}}

    return piece;
}

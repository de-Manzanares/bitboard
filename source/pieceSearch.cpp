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

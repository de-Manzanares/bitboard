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


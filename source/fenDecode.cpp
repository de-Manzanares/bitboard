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
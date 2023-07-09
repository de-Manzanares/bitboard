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

/// @file   fenDecode.cpp
/// @author de-Manzanares
/// @brief  Decodes a FEN string and updates the board.

#include "bitBoards.h"
#include <string>

void fenDecode(string& fenIn, ChessBoard& board)
{
    int fenIndex = 0;       // The index of the fen string.
    int coordIndex = 63;    // The index of the square.

    // Clear the bitboards.
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

    // While there are still characters in the fen string
    while (fenIndex<fenIn.size()) {
        // If the character is a number, skip that many squares.
        if (fenIn[fenIndex]>='1' && fenIn[fenIndex]<='8') {
            coordIndex -= fenIn[fenIndex]-'0';
            // If the character is a '/', ignore it.
        }
        else if (fenIn[fenIndex]!='/') {
            // If the character is a piece, add it to the board and move to the next square.
            addPiece(fenIn[fenIndex], coordIndex, board);
            coordIndex--;
        }
        // Move to the next character in the fen string.
        fenIndex++;
    }
}

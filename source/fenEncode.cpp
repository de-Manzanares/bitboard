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

/// @file   fenEncode.cpp
/// @author de-Manzanares
/// @brief  Encodes a chess board into a FEN string.

#include "bitBoards.h"

void fenEncode(ChessBoard& board)
{
    int countRank = 0;          // Every 8 squares, a new rank is started.
    int countEmptySquares = 0;  // Counts the number of empty squares
    bool nextRank;              // To track if a new rank is started.
    char piece;                 // The piece to be printed.

    // Starting at the index 63 (square a8) and going to 0 (square h1).
    for (int coordIndex = 63; coordIndex>=0; coordIndex--) {
        // Search the square for a piece.
        piece = pieceSearch(coordIndex, board);

        // If there was no piece, increment the number of empty squares.
        if (piece=='E') { countEmptySquares++; }

        // Increment the rank and check if a new rank is started.
        countRank++;
        nextRank = (countRank%8==0);

        // If there were one or more empty squares preceding a piece or a new rank,
        // print the number of empty squares, and reset the empty square counter.
        if (countEmptySquares>0 && ((piece!='E') || nextRank)) {
            cout << countEmptySquares;
            countEmptySquares = 0;
        }

        // If a piece was found, print its symbol to the FEN string.
        if (piece!='E') {
            cout << piece;
        }

        // If a new rank is started, print a slash to the FEN string.
        if (nextRank && coordIndex>0) { cout << "/"; }
    }
    // If there were empty squares at the end of the board, print the number of empty squares.
    if (countEmptySquares>0) { cout << countEmptySquares; }
    cout << endl << endl;
}

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

/// @file   printBitBoard.cpp
/// @author de-Manzanares
/// @brief  Prints an ASCII representation of the chess board to the console.

#include <iostream>
#include <string>
#include "bitBoards.h"

void printBitBoard(ChessBoard& board)
{
    int countSquares = 0;   // Every 8th square, a new rank is started.
    string line = "    +---+---+---+---+---+---+---+---+";
    char piece;             // The piece to be printed.

    cout << endl << line << endl << "    ";

    // Starting at the index 63 (square a8) and going to 0 (square h1).
    for (int coordIndex = 63; coordIndex>=0; coordIndex--) {
        cout << "| ";
        piece = pieceSearch(coordIndex, board);     // Search the square for a piece.
        if (piece=='E') {                           // If there was no piece, print a space.
            cout << " ";
        }
        else {
            cout << piece;                          // If there was a piece, print it.
        }
        cout << " ";

        countSquares++;  // Increment the counter and check if a new rank is started.
        if (countSquares%8==0) { cout << "|" << endl << line << endl << "    "; }
    }
    cout << endl;
}

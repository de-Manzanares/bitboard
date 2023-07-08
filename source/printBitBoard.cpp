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

#include <iostream>
#include <string>
#include "bitBoards.h"

using namespace std;

void printBitBoard(ChessBoard& board)
{
    int counter = 0;
    bool piecePrinted;
    string line = "    +---+---+---+---+---+---+---+---+";

    cout << endl << line << endl << "    ";

    for (int i = 63; i >= 0; i--)
    {
        uint64_t mask = static_cast<uint64_t>(1) << i;

        cout << "| ";
        if (board.black_pawn   & mask) { cout << "p" ; piecePrinted = true;}
        if (board.black_night  & mask) { cout << "n" ; piecePrinted = true;}
        if (board.black_bishop & mask) { cout << "b" ; piecePrinted = true;}
        if (board.black_rook   & mask) { cout << "r" ; piecePrinted = true;}
        if (board.black_queen  & mask) { cout << "q" ; piecePrinted = true;}
        if (board.black_king   & mask) { cout << "k" ; piecePrinted = true;}
        if (board.white_Pawn   & mask) { cout << "P" ; piecePrinted = true;}
        if (board.white_Night  & mask) { cout << "N" ; piecePrinted = true;}
        if (board.white_Bishop & mask) { cout << "B" ; piecePrinted = true;}
        if (board.white_Rook   & mask) { cout << "R" ; piecePrinted = true;}
        if (board.white_Queen  & mask) { cout << "Q" ; piecePrinted = true;}
        if (board.white_King   & mask) { cout << "K" ; piecePrinted = true;}
        cout << " ";

        if (!piecePrinted) { cout << " ";}
        piecePrinted = false;

        counter++;
        if (counter % 8 == 0) { cout << "|" << endl << line << endl << "    "; }
    }
    cout << endl;
}

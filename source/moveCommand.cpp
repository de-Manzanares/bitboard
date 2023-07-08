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
#include <sstream>
#include "bitBoards.h"

void moveCommand(stringstream& ss, ChessBoard& board)
{
    string from;
    string to;

    if (!(ss >> from >> to)) {
        cout << endl;
        cout << "Invalid move command"
             << endl << endl;
        return;
    }

    char pieceFrom;
    char pieceTo;
    int indexFrom = coordinateIndex(from);
    int indexTo   = coordinateIndex(to);

    if (indexFrom == 333 || indexTo == 333) {
        cout << "Command must be in the form" << endl
             << "mv <a-h><1-8> <a-h><1-8>" << endl << endl;
        return;
    }

    pieceFrom = pieceSearch(indexFrom, board);

    if (pieceFrom == 'E') {
        cout << from << " is empty" << endl << endl;
        return;
    }

    if (pieceFrom == 'P' || pieceFrom == 'p') {
        if (!movePawn(pieceFrom, indexFrom, indexTo, board)) {
            cout << "Illegal move" << endl << endl;
            return;
        }
    }
    // if (pieceFrom == 'N' || pieceFrom == 'n') {
    //     if (!moveKnight(pieceFrom, indexFrom, indexTo, board)) {
    //         cout << "Illegal move" << endl << endl;
    //         return;
    //     }
    // }
    if (pieceFrom == 'B' || pieceFrom == 'b') {
        if (!moveBishop(pieceFrom, indexFrom, indexTo, board)) {
            cout << "Illegal move" << endl << endl;
            return;
        }
    }
    if (pieceFrom == 'R' || pieceFrom == 'r') {
        if (!moveRook(pieceFrom, indexFrom, indexTo, board)) {
            cout << "Illegal move" << endl << endl;
            return;
        }
    }
    if (pieceFrom == 'Q' || pieceFrom == 'q') {
        if (!moveQueen(pieceFrom, indexFrom, indexTo, board)) {
            cout << "Illegal move" << endl << endl;
            return;
        }
    }
    if (pieceFrom == 'K' || pieceFrom == 'k') {
        if (!moveKing(pieceFrom, indexFrom, indexTo, board)) {
            cout << "Illegal move" << endl << endl;
            return;
        }
    }

    subtractPiece(pieceFrom, indexFrom, board);

     cout << "Moving " << from << " to " << to
          << endl << endl;

    pieceTo = pieceSearch(indexTo, board);

    if (pieceTo == 'E') {
        addPiece(pieceFrom, indexTo, board);
    }
    else
    {
        subtractPiece(pieceTo, indexTo, board);
        addPiece(pieceFrom, indexTo, board);
    }
}
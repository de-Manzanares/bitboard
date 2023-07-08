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

void addReplaceCommand(stringstream& ss, ChessBoard& board)
{
    char pieceAdd;
    string to;

    if (!(ss >> pieceAdd >> to)) {
        cout << endl;
        cout << "Invalid add command"
             << endl << endl;
        return;
    }

    int index = coordinateIndex(to);
    string validPieces = "KQRBNPkqrbnp";

    if (index == 333 || validPieces.find(pieceAdd) == string::npos) {
        cout << "Command must be in the form" << endl
             << "add <K|Q|R|B|N|P|k|q|r|b|n|p> <a-h><1-8>" << endl
             << "for example: add Q f8" << endl << endl;
        return;
    }

    char pieceRemove = pieceSearch(index, board);

    cout << "Adding " << pieceAdd << " to " << to
         << endl << endl;

    if (pieceRemove == 'E') {
        addPiece(pieceAdd, index, board);
    }
    else {
        subtractPiece(pieceRemove, index, board);
        addPiece(pieceAdd, index, board);
    }
}

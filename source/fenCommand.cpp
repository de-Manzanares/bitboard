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

/// @file   fenCommand.cpp
/// @author de-Manzanares
/// @brief  Handles the fen command.

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "bitBoards.h"

void fenCommand(stringstream& ss, ChessBoard& board)
{
    string direction;   // Updating board from fen string or printing current fen string.
    string fenIn;       // The fen string to update the board with.

    // If there is an input error, notify the user and return.
    if (!(ss >> direction)) {
        cout << endl;
        cout << "Invalid FEN command"
             << endl << endl;
        return;
    }

    // Valid directions are "in" and "out".
    set<string> validDirection = {"in", "out"};

    if (validDirection.find(direction)!=validDirection.end()) {
        // If the direction is "in", read the fen string and decode it.
        if (direction=="in") {
            ss >> fenIn;
            fenDecode(fenIn, board);
            // If the direction is "out", encode the board and print the fen string.
        }
        else {
            fenEncode(board);
        }
    }
}

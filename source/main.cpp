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

/// @file   main.cpp
/// @author de-Manzanares
/// @brief  Main file for the bitboard.

#include <iostream>
#include <string>
#include <sstream>
#include "bitBoards.h"

using namespace std;

int main()
{
    string commandLine;
    ChessBoard board;

    while (getline(cin, commandLine) && commandLine!="quit") {
        stringstream ss(commandLine);
        string command;
        ss >> command;

        if (command=="add") {
            addReplaceCommand(ss, board);
        }

        if (command=="d") {
            printBitBoard(board);
        }

        if (command=="fen") {
            fenCommand(ss, board);
        }

        if (command=="mv") {
            moveCommand(ss, board);
        }

       if (command=="pam") {
           printAllMoves(board);
       }
       if (command=="infw") {
           sideInfluence('w', board);
       }
       if (command=="infb") {
           sideInfluence('b', board);
       }
    }
    return 0;
}

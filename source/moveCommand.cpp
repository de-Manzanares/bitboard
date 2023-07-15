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

/// @file   moveCommand.cpp
/// @author de-Manzanares
/// @brief  Handles the move command.

#include <sstream>
#include "bitBoards.h"

bool isWhite(char pieceFrom);

void moveCommand(stringstream& ss, ChessBoard& board)
{
    string from;    // From square
    string to;      // To square
    bool CONTINUE;  // If true, continue with the move

    // If there is an input error, notify the user and return.
    if (!(ss >> from >> to)) {
        cout << endl;
        cout << "Invalid move command"
             << endl << endl;
        return;
    }

    char pieceFrom;     // The piece to move
    int indexFrom = coordinateToIndex(from);  // Index of the from square
    int indexTo = coordinateToIndex(to);      // Index of the to square

    // If either of the squares are invalid, notify the user and return.
    if (indexFrom==333 || indexTo==333) {
        cout << "Command must be in the form" << endl
             << "mv <a-h><1-8> <a-h><1-8>" << endl << endl;
        return;
    }

    // Otherwise, search for the piece to be moved on the specified square.
    pieceFrom = pieceSearch(indexFrom, board);

    // If there is no piece, notify the user and return.
    if (pieceFrom=='E') {
        cout << from << " is empty" << endl << endl;
        return;
    }

    if (board.whiteToMove && isWhite(pieceFrom)) {
        CONTINUE = true;
    }
    if (!board.whiteToMove && !isWhite(pieceFrom)) {
        CONTINUE = true;
    }
    if (board.whiteToMove && !isWhite(pieceFrom)) {
        CONTINUE = false;
        cout << "It is white's turn" << endl << endl;
    }
    if (!board.whiteToMove && isWhite(pieceFrom)) {
        CONTINUE = false;
        cout << "It is black's turn" << endl << endl;
    }

    if (CONTINUE) {
        // If the piece is a pawn, call the movePawn function.
        if (pieceFrom=='P' || pieceFrom=='p') {
            if (!movePawn(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }
        // If the piece is a knight, call the moveKnight function.
        if (pieceFrom=='N' || pieceFrom=='n') {
            if (!moveKnight(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }
        // If the piece is a bishop, call the moveBishop function.
        if (pieceFrom=='B' || pieceFrom=='b') {
            if (!moveBishop(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }
        // If the piece is a rook, call the moveRook function.
        if (pieceFrom=='R' || pieceFrom=='r') {
            if (!moveRook(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }
        // If the piece is a queen, call the moveQueen function.
        if (pieceFrom=='Q' || pieceFrom=='q') {
            if (!moveQueen(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }
        // If the piece is a king, call the moveKing function.
        if (pieceFrom=='K' || pieceFrom=='k') {
            if (!moveKing(pieceFrom, indexFrom, indexTo, board)) {
                cout << "Illegal move" << endl << endl;
                return;
            }
        }

        cout << "Moving " << from << " to " << to
             << endl << endl;

        movePiece(pieceFrom, indexFrom, indexTo, board);

        board.whiteToMove = !board.whiteToMove;
        board.halfMoveCount++;
    }
}

bool isWhite(char pieceFrom)
{
    return pieceFrom=='P' || pieceFrom=='N' || pieceFrom=='B' ||
            pieceFrom=='R' || pieceFrom=='Q' || pieceFrom=='K';
}

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

/// @file   FEN.cpp
/// @author de-Manzanares
/// @brief  For all things FEN

#include <sstream>
#include <set>
#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
// This function handles the `fen` command
//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
// This function DECODES the board into a fen string.
//----------------------------------------------------------------------------------------------------------------------
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

    updateBoard(board);
}

//----------------------------------------------------------------------------------------------------------------------
// This function ENCODES the board into a fen string.
//----------------------------------------------------------------------------------------------------------------------
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

    if (board.whiteToMove) { cout << " w "; }
    else { cout << " b "; }

    if (!board.whiteKingMoved) {
        if (!board.whiteKingSideRookMoved) { cout << "K"; }
        if (!board.whiteQueenSideRookMoved) { cout << "Q"; }
    }
    if (!board.blackKingMoved) {
        if (!board.blackKingSideRookMoved) { cout << "k"; }
        if (!board.blackQueenSideRookMoved) { cout << "q"; }
    }
    cout << endl << endl;
}

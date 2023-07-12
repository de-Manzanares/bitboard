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

/// @file   squareSearch.cpp
/// @author de-Manzanares
/// @brief  Checks a square to determine if it is empty, occupied by a friendly, or occupied by an enemy.

#include <vector>
#include <string>
#include "bitBoards.h"

std::vector<int> squareSearch(char pieceFrom, int& flag, int& canMove, int indexTo, ChessBoard& board)
{
    string whitePieces = "KQRBNP";  // All white pieces
    string blackPieces = "kqrbnp";  // All black pieces
    string capturePieces;           // To define which pieces can be captured
    string collisionPieces;         // To define which pieces can block movement
    char pieceTo;                   // To store the piece at the destination square

    // If the piece to move is white, set the capture pieces to black and the collision pieces to white.
    // If the piece to move is black, set the capture pieces to white and the collision pieces to black.
    if (whitePieces.find(pieceFrom)!=string::npos) {
        capturePieces = blackPieces;
        collisionPieces = whitePieces;
    }
    if (blackPieces.find(pieceFrom)!=string::npos) {
        capturePieces = whitePieces;
        collisionPieces = blackPieces;
    }

    // Using flag from previous squareSearch
    // If the previous squareSearch says the piece cannot move further, don't bother checking the next square.
    // If the previous squareSearch says a piece was captured, don't bother checking the next square.
    if (!(canMove)) { canMove = false; }
    if (flag==2) { canMove = false; }

    // If the previous squareSearch says the piece can move further, check the next square.
    // Set flag to 0 if the next square is occupied by a friendly.
    // Set flag to 1 if the next square is empty.
    // Set flag to 2 if the next square is occupied by an enemy.
    // Set canMove to false if the next square is occupied by a friendly.
    if (flag==1) {
        pieceTo = pieceSearch(indexTo, board);
        if (collisionPieces.find(pieceTo)!=string::npos) { flag = 0; }
        if (pieceTo=='E') { flag = 1; }
        if (capturePieces.find(pieceTo)!=string::npos) { flag = 2; }

        if (flag==0) { canMove = false; }
        if (flag==1) { canMove = true; }
        if (flag==2) { canMove = true; }
    }

    return {flag, canMove};
}

std::vector<int> squareSearchKnight(char pieceFrom, int& flag, int& canMove, int indexTo, ChessBoard& board)
{
    string whitePieces = "KQRBNP";  // All white pieces
    string blackPieces = "kqrbnp";  // All black pieces
    string capturePieces;           // To define which pieces can be captured
    string collisionPieces;         // To define which pieces can block movement
    char pieceTo;                   // To store the piece at the destination square

    // If the piece to move is white, set the capture pieces to black and the collision pieces to white.
    // If the piece to move is black, set the capture pieces to white and the collision pieces to black.
    if (whitePieces.find(pieceFrom)!=string::npos) {
        capturePieces = blackPieces;
        collisionPieces = whitePieces;
    }
    if (blackPieces.find(pieceFrom)!=string::npos) {
        capturePieces = whitePieces;
        collisionPieces = blackPieces;
    }

    // Using flag from previous squareSearch
    // If the previous squareSearch says the piece cannot move further, don't bother checking the next square.
    // If the previous squareSearch says a piece was captured, don't bother checking the next square.
    if (!(canMove)) { canMove = false; }
    // if (flag==2) { canMove = false; }

    // If the previous squareSearch says the piece can move further, check the next square.
    // Set flag to 0 if the next square is occupied by a friendly.
    // Set flag to 1 if the next square is empty.
    // Set flag to 2 if the next square is occupied by an enemy.
    // Set canMove to false if the next square is occupied by a friendly.
    if (flag==1) {
        pieceTo = pieceSearch(indexTo, board);
        if (collisionPieces.find(pieceTo)!=string::npos) { flag = 0; }
        if (pieceTo=='E') { flag = 1; }
        if (capturePieces.find(pieceTo)!=string::npos) { flag = 2; }

        if (flag==0) { canMove = false; }
        if (flag==1) { canMove = true; }
        if (flag==2) { canMove = true; }
    }

    return {flag, canMove};
}

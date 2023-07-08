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

#include <vector>
#include <string>
#include "bitBoards.h"

std::vector<int> squareSearch (char pieceFrom, int& flag, int& canMove , int indexTo, ChessBoard& board)
{
    string whitePieces = "KQRBNP";
    string blackPieces = "kqrbnp";
    string capturePieces;
    string collisionPieces;
    char pieceTo;

    if (whitePieces.find(pieceFrom) != string::npos) {
        capturePieces = "kqrbnp";
        collisionPieces = "KQRBNP";
    }
    if (blackPieces.find(pieceFrom) != string::npos) {
        capturePieces = "KQRBNP";
        collisionPieces = "kqrbnp";
    }

    if (!(canMove)) {canMove = false;}
    if (flag == 2) {canMove = false;}

    if (flag == 1) {
        pieceTo = pieceSearch(indexTo, board);
        if (collisionPieces.find(pieceTo) != string::npos) {flag = 0;}
        if (pieceTo == 'E') {flag = 1;}
        if (capturePieces.find(pieceTo) != string::npos) {flag = 2;}

        if (flag == 0) {canMove = false;}
        if (flag == 1) {canMove = true;}
        if (flag == 2) {canMove = true;}
    }

    return {flag, canMove};
}

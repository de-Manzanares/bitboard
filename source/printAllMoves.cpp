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

/// @file   printAllMoves.cpp
/// @author de-Manzanares
/// @brief  Print a list, to depth 1, of all possible moves for all pieces of both colors.

#include "bitBoards.h"

void calculateMovesCastling
        (char pieceFrom, int indexFrom, vector<int>& range, ChessBoard& board);
bool squaresAreClear(vector<int> squares, ChessBoard& board);
bool rangeValidationKing(char pieceFrom, vector<int> range, int indexTo, ChessBoard& board);
bool castlingCheckCheck(char pieceFrom, vector<int> moves, ChessBoard& board);

void printAllMoves(ChessBoard& board)
{
    // For each square on the board, find the piece on it and print all possible moves for that piece.
    for (int i=0; i<=63; i++) {
        vector<int> range;
        char pieceFrom = pieceSearch(i, board);

        if (pieceFrom != 'E') {
            if (pieceFrom == 'P' || pieceFrom == 'p') {
                calculateMovePawn(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
            if (pieceFrom == 'N' || pieceFrom == 'n') {
                calculateMoveKnight(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
            if (pieceFrom == 'B' || pieceFrom == 'b') {
                calculateMovesDiagonal(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
            if (pieceFrom == 'R' || pieceFrom == 'r') {
                calculateMovesVertical(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
            if (pieceFrom == 'Q' || pieceFrom == 'q') {
                calculateMovesDiagonal(pieceFrom, i, range, board);
                calculateMovesHorizontal(pieceFrom, i, range, board);
                calculateMovesVertical(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
            if (pieceFrom == 'K' || pieceFrom == 'k') {
                calculateMovesDiagonal(pieceFrom, i, range, board);
                calculateMovesHorizontal(pieceFrom, i, range, board);
                calculateMovesCastling(pieceFrom, i, range, board);
                calculateMovesVertical(pieceFrom, i, range, board);
                cout << pieceFrom << " " << indexToCoordinate(i) << " : ";
                printCoordinates(range);
            }
        }
    }
    cout << endl;
}

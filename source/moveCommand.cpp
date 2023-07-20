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
/// @brief  User initiated command to move a piece on the board.

#include <sstream>
#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
//  Function Prototypes
//----------------------------------------------------------------------------------------------------------------------
bool isWhite(char pieceFrom);
void calculateMovesKnightHelper
        (char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                ChessBoard& board);
bool rangeValidationRook(char pieceFrom, int indexFrom, vector<int> range, int indexTo, ChessBoard& board);

//----------------------------------------------------------------------------------------------------------------------
//  Handles the user initiated move command.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Handles the user initiated move command.
///
/// If the input is invalid, notify the user and return; otherwise, call the appropriate move function.
/// The move function checks if the move is legal. If the move is legal, the board is modified.
/// If the move is illegal, notify the user and return.
///
/// @post If the move is legal the `board` is modified.
///
/// @param ss The stringstream containing the command.
/// @param board The chess board.

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

//----------------------------------------------------------------------------------------------------------------------
//  Checks the color of a piece.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Check the color of a piece.
///
/// Used within the `moveCommand()` to enforce the turn order.
///
/// @param pieceFrom The piece to check.
///
/// @return True - the piece is white. <br>
///         False - the piece is black.

bool isWhite(const char pieceFrom)
{
    return pieceFrom=='P' || pieceFrom=='N' || pieceFrom=='B' ||
            pieceFrom=='R' || pieceFrom=='Q' || pieceFrom=='K';
}

//----------------------------------------------------------------------------------------------------------------------
// Checks if a given BISHOP move is legal.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks if a given bishop move is legal.
///
/// Use `calculateMovesDiagonal()` to populate a vector with all possible moves for the bishop, then check if the target
/// square is in the range.
///
/// @param pieceFrom To verify that the piece is a bishop.
/// @param indexFrom The starting position of the bishop.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the move is legal. <br>
///         False - the move is illegal.

bool moveBishop(const char pieceFrom, const int indexFrom, const int indexTo, ChessBoard& board)
{
    if (pieceFrom=='B' || pieceFrom=='b') {

        vector<int> range;

        calculateMovesDiagonal(pieceFrom, indexFrom, range, board);

        if (rangeValidation(range, indexTo))
            return true;
        return false;
    }
    return false;
}

//----------------------------------------------------------------------------------------------------------------------
//  Checks if a given KNIGHT move is legal.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks if a given knight move is legal.
///
/// Based on the starting square, select 1 of 17 possible move sets and pass it to `calculateMovesKnightHelper()` which
/// then modifies the vector `range` to contain all legal moves from the given set. Finally, check if the target square
/// is in the range.
///
/// @param pieceFrom Serves no purpose currently.
/// @param indexFrom The starting position of the knight.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the move is legal. <br>
///         False - the move is illegal.

bool moveKnight(const char pieceFrom, const int indexFrom, const int indexTo, ChessBoard& board)
{
    const int ForwardLeft = indexFrom+17;
    const int ForwardRight = indexFrom+15;
    const int LeftForward = indexFrom+10;
    const int RightForward = indexFrom+6;
    const int LeftBack = indexFrom-6;
    const int RightBack = indexFrom-10;
    const int BackLeft = indexFrom-15;
    const int BackRight = indexFrom-17;

    std::vector<int> result;
    std::vector<int> range;

    int flag = 1;
    int canMove = 1;
    int limit = 2;
    vector<int> moves;

    // For reference
    // a8 through h1 is 63 through 0
    // {a8, b8, g8, h8, a7, b7, g7, h7, a2, b2, g2, h2, a1, b1, g1, h1}
    // {63, 62, 57, 56, 55, 54, 49, 48, 15, 14,  9,  8,  7,  6,  1,  0}

    switch (indexFrom) {
    case 63:moves = {BackRight, RightBack};
        break;
    case 62:moves = {BackRight, RightBack, BackLeft};
        break;
    case 57:moves = {BackRight, BackLeft, LeftBack};
        break;
    case 56:moves = {BackLeft, LeftBack};
        break;
    case 55:moves = {BackRight, RightBack, RightForward};
        break;
    case 54:moves = {BackRight, RightBack, RightForward, BackLeft};
        break;
    case 49:moves = {BackRight, BackLeft, LeftBack, LeftForward};
        break;
    case 48:moves = {BackLeft, LeftBack, LeftForward};
        break;
    case 15:moves = {RightBack, RightForward, ForwardRight};
        break;
    case 14:moves = {RightBack, RightForward, ForwardRight, ForwardLeft};
        break;
    case 9:moves = {LeftBack, LeftForward, ForwardLeft, ForwardRight};
        break;
    case 8:moves = {LeftBack, LeftForward, ForwardLeft};
        break;
    case 7:moves = {RightForward, ForwardRight};
        break;
    case 6:moves = {RightForward, ForwardRight, ForwardLeft};
        break;
    case 1:moves = {LeftForward, ForwardLeft, ForwardRight};
        break;
    case 0:moves = {LeftForward, ForwardLeft};
        break;
    default:moves = {BackRight, RightBack, BackLeft, LeftBack, RightForward, ForwardRight, LeftForward, ForwardLeft};
    }

    calculateMovesKnightHelper(pieceFrom, range, flag, canMove, moves, limit, board);

    if (rangeValidation(range, indexTo))
        return true;
    return false;
}

//----------------------------------------------------------------------------------------------------------------------
//  Checks if a given QUEEN move is legal.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks if a given queen move is legal.
///
/// Use `calculateMovesDiagonal()`, `calculateMovesHorizontal()`, and `calculateMovesVertical()` to populate a vector
/// with all possible moves for the queen, then check if the target square is in the range.
///
/// @param pieceFrom To verify that the piece is a queen.
/// @param indexFrom The starting position of the queen.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the move is legal. <br>
///        False - the move is illegal.

bool moveQueen(const char pieceFrom, const int indexFrom, const int indexTo, ChessBoard& board)
{
    if (pieceFrom=='Q' || pieceFrom=='q') {

        vector<int> range;

        calculateMovesDiagonal(pieceFrom, indexFrom, range, board);
        calculateMovesHorizontal(pieceFrom, indexFrom, range, board);
        calculateMovesVertical(pieceFrom, indexFrom, range, board);

        if (rangeValidation(range, indexTo))
            return true;
        return false;
    }
    return false;
}

//----------------------------------------------------------------------------------------------------------------------
//  Checks if a given ROOK move is legal.
//------------------------------------------------------------------------------
/// @brief Checks if a given rook move is legal.
///
/// Use `calculateMovesHorizontal()` and `calculateMovesVertical()` to populate a vector with all possible moves for the
/// rook, then check if the target square is in the range. Furthermore, `rangeValidationRook()` contains additional
/// logic to enforce the castling rules - if the rook is moved, it is no longer eligible for castling.
///
/// @param pieceFrom To verify that the piece is a rook.
/// @param indexFrom The starting position of the rook.
/// @param indexTo The user supplied target square.
/// @param board The chess board.
///
/// @return True - the move is legal. <br>
///         False - the move is illegal.

bool moveRook(const char pieceFrom, const int indexFrom, const int indexTo, ChessBoard& board)
{
    if (pieceFrom=='R' || pieceFrom=='r') {

        vector<int> range;

        calculateMovesHorizontal(pieceFrom, indexFrom, range, board);
        calculateMovesVertical(pieceFrom, indexFrom, range, board);

        if (rangeValidationRook(pieceFrom, indexFrom, range, indexTo, board))
            return true;
        return false;
    }
    return false;
}

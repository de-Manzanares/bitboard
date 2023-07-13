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

/// @file   bitwise.cpp
/// @author de-Manzanares
/// @brief  Contains functions for bitwise operations.

#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
// Add a piece to the board.
//----------------------------------------------------------------------------------------------------------------------
void addPiece(char piece, int index, ChessBoard &board)
{
    // The `mask` is used to perform bitwise operations on specific bits.
    uint64_t mask = static_cast<uint64_t>(1) << index;

    // On the specified bitboard, and at the specified bit, set the bit to 1.
    if (piece == 'p') { board.black_pawn   = board.black_pawn   + mask; }
    if (piece == 'n') { board.black_night  = board.black_night  + mask; }
    if (piece == 'b') { board.black_bishop = board.black_bishop + mask; }
    if (piece == 'r') { board.black_rook   = board.black_rook   + mask; }
    if (piece == 'q') { board.black_queen  = board.black_queen  + mask; }
    if (piece == 'k') { board.black_king   = board.black_king   + mask; }
    if (piece == 'P') { board.white_Pawn   = board.white_Pawn   + mask; }
    if (piece == 'N') { board.white_Night  = board.white_Night  + mask; }
    if (piece == 'B') { board.white_Bishop = board.white_Bishop + mask; }
    if (piece == 'R') { board.white_Rook   = board.white_Rook   + mask; }
    if (piece == 'Q') { board.white_Queen  = board.white_Queen  + mask; }
    if (piece == 'K') { board.white_King   = board.white_King   + mask; }

    updateBoard(board);
}

//----------------------------------------------------------------------------------------------------------------------
// Subtract a piece from the board.
//----------------------------------------------------------------------------------------------------------------------
void subtractPiece(char piece, int index, ChessBoard& board)
{
    // The `mask` is used to perform bitwise operations on specific bits.
    uint64_t mask = static_cast<uint64_t>(1) << index;

    // On the specified bitboard, and at the specified bit, set the bit to 0.
    if (piece == 'p') { board.black_pawn   = board.black_pawn   - mask; }
    if (piece == 'n') { board.black_night  = board.black_night  - mask; }
    if (piece == 'b') { board.black_bishop = board.black_bishop - mask; }
    if (piece == 'r') { board.black_rook   = board.black_rook   - mask; }
    if (piece == 'q') { board.black_queen  = board.black_queen  - mask; }
    if (piece == 'k') { board.black_king   = board.black_king   - mask; }
    if (piece == 'P') { board.white_Pawn   = board.white_Pawn   - mask; }
    if (piece == 'N') { board.white_Night  = board.white_Night  - mask; }
    if (piece == 'B') { board.white_Bishop = board.white_Bishop - mask; }
    if (piece == 'R') { board.white_Rook   = board.white_Rook   - mask; }
    if (piece == 'Q') { board.white_Queen  = board.white_Queen  - mask; }
    if (piece == 'K') { board.white_King   = board.white_King   - mask; }

    updateBoard(board);
}

//----------------------------------------------------------------------------------------------------------------------
// Search for a piece on the board.
//----------------------------------------------------------------------------------------------------------------------
char pieceSearch(int index, const ChessBoard& board)
{
    char piece = 'E';   // E for empty

    // The `mask` is used to check if the bit at the given index is set.
    uint64_t mask = static_cast<uint64_t>(1) << index;

    // If the bit is set, then the piece is found.
    if (board.black_pawn   & mask) { piece = 'p' ; return piece ;}
    if (board.black_night  & mask) { piece = 'n' ; return piece ;}
    if (board.black_bishop & mask) { piece = 'b' ; return piece ;}
    if (board.black_rook   & mask) { piece = 'r' ; return piece ;}
    if (board.black_queen  & mask) { piece = 'q' ; return piece ;}
    if (board.black_king   & mask) { piece = 'k' ; return piece ;}
    if (board.white_Pawn   & mask) { piece = 'P' ; return piece ;}
    if (board.white_Night  & mask) { piece = 'N' ; return piece ;}
    if (board.white_Bishop & mask) { piece = 'B' ; return piece ;}
    if (board.white_Rook   & mask) { piece = 'R' ; return piece ;}
    if (board.white_Queen  & mask) { piece = 'Q' ; return piece ;}
    if (board.white_King   & mask) { piece = 'K' ; return piece ;}

    return piece;
}

//----------------------------------------------------------------------------------------------------------------------
// Move a piece on the board.
//----------------------------------------------------------------------------------------------------------------------
void movePiece(char pieceFrom, int indexFrom, int indexTo, ChessBoard& board)
{
    // Remove the piece its original square.
    // If the target square is empty, add the piece to be moved.
    // If the target square is occupied, remove the piece on the target square then add piece to be moved.

    char pieceTo = pieceSearch(indexTo, board);
    subtractPiece(pieceFrom, indexFrom, board);
    if (pieceTo=='E') {
        addPiece(pieceFrom, indexTo, board);
    }
    else {
        subtractPiece(pieceTo, indexTo, board);
        addPiece(pieceFrom, indexTo, board);
    }
}
//----------------------------------------------------------------------------------------------------------------------
// Update the board.
//----------------------------------------------------------------------------------------------------------------------
void updateBoard(ChessBoard& board)
{
    board.black_pieces = board.black_pawn | board.black_night | board.black_bishop
            | board.black_rook | board.black_queen | board.black_king;
    board.white_pieces = board.white_Pawn | board.white_Night | board.white_Bishop
            | board.white_Rook | board.white_Queen | board.white_King;
}

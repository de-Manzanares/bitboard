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

/// @file   calculateMovesSliding.cpp
/// @brief  Calculate range for sliding pieces.
///         - calculate diagonal moves
///         - calculate horizontal moves
///         - calculate vertical moves

#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
// Calculates DIAGONAL range
///---------------------------------------------------------------------------------------------------------------------
/// @brief Calculates diagonal range
///
/// @post `range` is populated with all possible diagonal moves.
///
/// @param pieceFrom The piece to calculate the moves for - the king follows different calculations.
/// @param indexFrom The starting position of the piece.
/// @param range A vector of integers that will be populated with a given piece's range of diagonal moves.
/// @param board The chess board.

void calculateMovesDiagonal(const char pieceFrom, const int indexFrom, vector<int>& range, const ChessBoard& board)
{
    // The king is a special case.
    if (pieceFrom!='K' && pieceFrom!='k') {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        // Forward Diagonal Left
        const int FDL_ONE = indexFrom+9*1;
        const int FDL_TWO = indexFrom+9*2;
        const int FDL_THREE = indexFrom+9*3;
        const int FDL_FOUR = indexFrom+9*4;
        const int FDL_FIVE = indexFrom+9*5;
        const int FDL_SIX = indexFrom+9*6;
        const int FDL_SEVEN = indexFrom+9*7;
        // Forward Diagonal Right
        const int FDR_ONE = indexFrom+7*1;
        const int FDR_TWO = indexFrom+7*2;
        const int FDR_THREE = indexFrom+7*3;
        const int FDR_FOUR = indexFrom+7*4;
        const int FDR_FIVE = indexFrom+7*5;
        const int FDR_SIX = indexFrom+7*6;
        const int FDR_SEVEN = indexFrom+7*7;
        // Backward Diagonal Left
        const int BDL_ONE = indexFrom-7*1;
        const int BDL_TWO = indexFrom-7*2;
        const int BDL_THREE = indexFrom-7*3;
        const int BDL_FOUR = indexFrom-7*4;
        const int BDL_FIVE = indexFrom-7*5;
        const int BDL_SIX = indexFrom-7*6;
        const int BDL_SEVEN = indexFrom-7*7;
        // Backward Diagonal Right
        const int BDR_ONE = indexFrom-9*1;
        const int BDR_TWO = indexFrom-9*2;
        const int BDR_THREE = indexFrom-9*3;
        const int BDR_FOUR = indexFrom-9*4;
        const int BDR_FIVE = indexFrom-9*5;
        const int BDR_SIX = indexFrom-9*6;
        const int BDR_SEVEN = indexFrom-9*7;

        int leftLimit;          // The number of squares to the left of the piece.
        int rightLimit;         // The number of squares to the right of the piece.
        char fileFrom;          // The file of the piece - used to calculate the left and right limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`

        // Calculate the left and right limits.
        fileFrom = getFile(indexFrom);
        leftLimit = fileFrom-'a';
        rightLimit = 'h'-fileFrom;

        // Calculate the range for each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {FDL_ONE, FDL_TWO, FDL_THREE, FDL_FOUR, FDL_FIVE, FDL_SIX, FDL_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {FDR_ONE, FDR_TWO, FDR_THREE, FDR_FOUR, FDR_FIVE, FDR_SIX, FDR_SEVEN}, rightLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {BDL_ONE, BDL_TWO, BDL_THREE, BDL_FOUR, BDL_FIVE, BDL_SIX, BDL_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {BDR_ONE, BDR_TWO, BDR_THREE, BDR_FOUR, BDR_FIVE, BDR_SIX, BDR_SEVEN}, rightLimit, board);

        // TODO Why are there out of bounds values in the range? It seemed like it was only happening for the diagonal.
        // Remove out of bounds values from the range.
        cleanRange(range);
    }
        // The king is a special case.
    else {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        const int FDL_ONE = indexFrom+9*1;      // Forward Diagonal Left
        const int FDR_ONE = indexFrom+7*1;      // Forward Diagonal Right
        const int BDL_ONE = indexFrom-7*1;      // Backward Diagonal Left
        const int BDR_ONE = indexFrom-9*1;      // Backward Diagonal Right

        int leftLimit;          // The number of squares to the left of the piece.
        int rightLimit;         // The number of squares to the right of the piece.
        char fileFrom;          // The file of the piece - used to calculate the left and right limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`.

        // Calculate the left and right limits.
        fileFrom = getFile(indexFrom);
        if (fileFrom-'a'>0) {   // If the piece is not on the left edge of the board.
            leftLimit = 1;      // The left limit is 1.
        }
        else {
            leftLimit = 0;      // Otherwise, the left limit is 0.
        }
        if ('h'-fileFrom>0) {   // If the piece is not on the right edge of the board.
            rightLimit = 1;     // The right limit is 1.
        }
        else {
            rightLimit = 0;     // Otherwise, the right limit is 0.
        }

        // Calculate the range in each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove, {FDL_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {FDR_ONE}, rightLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {BDL_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {BDR_ONE}, rightLimit, board);

        // Remove out of bounds values from the range.
        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Calculates HORIZONTAL range
///---------------------------------------------------------------------------------------------------------------------
/// @brief Calculates horizontal range
///
/// @post `range` is populated with all possible horizontal moves.
///
/// @param pieceFrom The piece to calculate the moves for - the king follows different calculations.
/// @param indexFrom The starting position of the piece.
/// @param range A vector of integers that will be populated with a given piece's range of horizontal moves.
/// @param board The chess board.

void calculateMovesHorizontal(const char pieceFrom, const int indexFrom, vector<int>& range, const ChessBoard& board)
{
    // The king is a special case.
    if (pieceFrom!='K' && pieceFrom!='k') {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        // Left
        const int L_ONE = indexFrom+1;
        const int L_TWO = indexFrom+2;
        const int L_THREE = indexFrom+3;
        const int L_FOUR = indexFrom+4;
        const int L_FIVE = indexFrom+5;
        const int L_SIX = indexFrom+6;
        const int L_SEVEN = indexFrom+7;
        // Right
        const int R_ONE = indexFrom-1;
        const int R_TWO = indexFrom-2;
        const int R_THREE = indexFrom-3;
        const int R_FOUR = indexFrom-4;
        const int R_FIVE = indexFrom-5;
        const int R_SIX = indexFrom-6;
        const int R_SEVEN = indexFrom-7;

        int leftLimit;          // The number of squares to the left of the piece.
        int rightLimit;         // The number of squares to the right of the piece.
        char fileFrom;          // The file of the piece - used to calculate the left and right limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`.

        // Calculate the left and right limits.
        fileFrom = getFile(indexFrom);
        leftLimit = fileFrom-'a';
        rightLimit = 'h'-fileFrom;

        // Calculate the range in each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {L_ONE, L_TWO, L_THREE, L_FOUR, L_FIVE, L_SIX, L_SEVEN}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {R_ONE, R_TWO, R_THREE, R_FOUR, R_FIVE, R_SIX, R_SEVEN}, rightLimit, board);

        // Remove out of bounds values from the range.
        cleanRange(range);
    }
        // The king is a special case.
    else {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        // Left
        const int L_ONE = indexFrom+1;
        // Right
        const int R_ONE = indexFrom-1;

        int leftLimit;          // The number of squares to the left of the piece.
        int rightLimit;         // The number of squares to the right of the piece.
        char fileFrom;          // The file of the piece - used to calculate the left and right limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`.

        // Calculate the left and right limits.
        fileFrom = getFile(indexFrom);
        if (fileFrom-'a'>0) {   // If the piece is not on the left edge of the board.
            leftLimit = 1;      // The left limit is 1.
        }
        else {
            leftLimit = 0;      // Otherwise, the left limit is 0.
        }
        if ('h'-fileFrom>0) {   // If the piece is not on the right edge of the board.
            rightLimit = 1;     // The right limit is 1.
        }
        else {
            rightLimit = 0;     // Otherwise, the right limit is 0.
        }

        // Calculate the range in each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove, {L_ONE}, leftLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {R_ONE}, rightLimit, board);

        // Remove out of bounds values from the range.
        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Calculates VERTICAL range
///---------------------------------------------------------------------------------------------------------------------
/// @brief Calculates vertical range
///
/// @post `range` is populated with all possible horizontal moves.
///
/// @param pieceFrom The piece to calculate the moves for - the king follows different calculations.
/// @param indexFrom The starting position of the piece.
/// @param range A vector of integers that will be populated with a given piece's range of vertical moves.
/// @param board The chess board.

void calculateMovesVertical(const char pieceFrom, const int indexFrom, vector<int>& range, const ChessBoard& board)
{
    // The king is a special case.
    if (pieceFrom!='K' && pieceFrom!='k') {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        // Forward
        const int F_ONE = indexFrom+8*1;
        const int F_TWO = indexFrom+8*2;
        const int F_THREE = indexFrom+8*3;
        const int F_FOUR = indexFrom+8*4;
        const int F_FIVE = indexFrom+8*5;
        const int F_SIX = indexFrom+8*6;
        const int F_SEVEN = indexFrom+8*7;
        // Backward
        const int B_ONE = indexFrom-8*1;
        const int B_TWO = indexFrom-8*2;
        const int B_THREE = indexFrom-8*3;
        const int B_FOUR = indexFrom-8*4;
        const int B_FIVE = indexFrom-8*5;
        const int B_SIX = indexFrom-8*6;
        const int B_SEVEN = indexFrom-8*7;

        int topLimit;           // The number of squares above the piece.
        int bottomLimit;        // The number of squares below the piece.
        int rankFrom;           // The rank of the piece - used to calculate the top and bottom limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`.

        // Calculate the top and bottom limits.
        rankFrom = indexFrom/8+1;
        topLimit = 8-rankFrom;
        bottomLimit = rankFrom-1;

        // Calculate the range in each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {F_ONE, F_TWO, F_THREE, F_FOUR, F_FIVE, F_SIX, F_SEVEN}, topLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove,
                {B_ONE, B_TWO, B_THREE, B_FOUR, B_FIVE, B_SIX, B_SEVEN}, bottomLimit, board);

        // Remove out of bounds values from the range.
        cleanRange(range);
    }
        // The king is a special case.
    else {
        // Moves and their corresponding indices.
        // Forward, Backward, Left, and Right are from the perspective of the white player.
        // The same moves are used for both white and black pieces.
        // Forward
        const int F_ONE = indexFrom+8*1;
        // Backward
        const int B_ONE = indexFrom-8*1;

        int topLimit;           // The number of squares above the piece.
        int bottomLimit;        // The number of squares below the piece.
        int rankFrom;           // The rank of the piece - used to calculate the top and bottom limits.
        int flag = 1;           // Flag for `squareSearch()` - indicates the occupancy of the square
        int canMove = 1;        // Flag for `squareSearch()` - indicates whether the piece can move to the square
        vector<int> result;     // The result of `squareSearch()`.

        // Calculate the top and bottom limits.
        rankFrom = indexFrom/8+1;
        if (8-rankFrom>0) {     // If the piece is not on the top edge of the board.
            topLimit = 1;       // The top limit is 1.
        }
        else {
            topLimit = 0;       // Otherwise, the top limit is 0.
        }
        if (rankFrom-1>0) {     // If the piece is not on the bottom edge of the board.
            bottomLimit = 1;    // The bottom limit is 1.
        }
        else {
            bottomLimit = 0;    // Otherwise, the bottom limit is 0.
        }

        // Calculate the range in each direction and append it to the `range` vector.
        calculateMovesHelper(pieceFrom, range, flag, canMove, {F_ONE}, topLimit, board);
        calculateMovesHelper(pieceFrom, range, flag, canMove, {B_ONE}, bottomLimit, board);

        // Remove out of bounds values from the range.
        cleanRange(range);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Helper function for calculating sliding moves
///---------------------------------------------------------------------------------------------------------------------
/// @brief Feeds a list of moves to `squareSearch()` and uses the feedback to create a list of legal moves.
///
/// `calculateMovesHelper()` feeds `squareSearch()` a list of indices to be searched.
/// If the square is flagged as empty, that move is added to `range`, and the next index is passed to `squareSearch()`.
/// If the square is occupied by an enemy, that move is added to `range` because a capture is possible, but the search
/// stops because the piece cannot continue moving after a capture. If the square is occupied by an ally, that move is
/// not added to `range` because the piece cannot move to a square occupied by an ally, and the search stops because the
/// piece cannot continue moving after collision.
///
/// @post `{flag, canMove}` is modified
/// @post `range` is populated with all possible moves.
///
/// @param pieceFrom To tell `squareSearch()` which pieces cause capture or collision.
/// @param range A list to be populated with all possible moves.
/// @param flag Flags a square as empty, occupied by an enemy, or occupied by an ally.
/// @param canMove Flags a square as a valid move.
/// @param moves A vector of integers that contains the indices of the squares to be searched.
/// @param limit The limit of the search, e.g. we don't need to search left if the piece is on the left edge of the
///                 board.
/// @param board The chess board.

void calculateMovesHelper
        (const char pieceFrom, vector<int>& range, int& flag, int& canMove, const vector<int>& moves, int limit,
                const ChessBoard& board)
{
    std::vector<int> result;    // To store the indices of the squares that can be moved to.
    flag = 1;                   // To flag a square as empty, occupied by an enemy, or occupied by an ally.
    canMove = 1;                // To tell `squareSearch()` whether to continue searching for moves.

    // The `limit` puts a stopper on the sliding search
    // e.g. we don't need to search left if the piece is on the left edge of the board.
    // Search each square in the given direction until a collision, capture, or the edge of the board.
    // If the square is a valid move, add it to the range.
    for (int i = 0; i<limit; i++) {
        result = squareSearch(pieceFrom, flag, canMove, moves[i], board);
        if (result[1])
            range.push_back(moves[i]);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Flag a square as empty, occupied by an enemy, or occupied by an ally.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Flag a square as empty, occupied by an enemy, or occupied by an ally.
///
/// Searches a single square at a time. A square can have three states:
/// - Empty --- the piece can move to the square and possibly further.
/// - Occupied by an enemy --- the piece can move to the square but cannot move further.
/// - Occupied by an ally --- the piece cannot move to the square and cannot move further.
///
/// The vector `{flag, canMove}` tells us what happened in the previous square thereby determining
/// the treatment of the next square. `squareSearch()` only searches one square at a time. To "slide across the board",
/// so to speak, `calculateMovesHelper()` feeds this function a list of squares to search, stopping when
/// `squareSearch()` indicates a capture or collision, or when the edge of the board is reached.
///
/// @post vector `{flag, canMove}` is modified.
///
/// @param pieceFrom Indicates side, determining which pieces can be captured which cause collision.
/// @param flag Flags a square as empty, occupied by an enemy, or occupied by an ally.
/// @param canMove Flags whether the piece can move to the square.
/// @param indexTo The index of the square to be searched.
///
/// @return vector `{flag, canMove}` --- indicating the condition of the previous square, thereby determining
///         the treatment of the next square.

vector<int> squareSearch(const char pieceFrom, int& flag, int& canMove, int indexTo, const ChessBoard& board)
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
    if (!(canMove)) {
        canMove = false;
    }
    if (flag==2) {
        canMove = false;
    }

    // If the previous squareSearch says the piece can move further, check the next square.
    // Set flag to 0 if the next square is occupied by a friendly.
    // Set flag to 1 if the next square is empty.
    // Set flag to 2 if the next square is occupied by an enemy.
    // Set canMove to false if the next square is occupied by a friendly.
    if (flag==1) {
        pieceTo = pieceSearch(indexTo, board);
        if (collisionPieces.find(pieceTo)!=string::npos) {
            flag = 0;
        }
        if (pieceTo=='E') {
            flag = 1;
        }
        if (capturePieces.find(pieceTo)!=string::npos) {
            flag = 2;
        }

        if (flag==0) {
            canMove = false;
        }
        if (flag==1) {
            canMove = true;
        }
        if (flag==2) {
            canMove = true;
        }
    }
    return {flag, canMove};
}

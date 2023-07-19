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

/// @file   indices.cpp
/// @author de-Manzanares
/// @brief  Miscellaneous functions related to coordinates and indices.

#include "bitBoards.h"

//----------------------------------------------------------------------------------------------------------------------
// Converts chess algebraic notation to index notation.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Converts chess algebraic notation to index notation.
///
/// To coincide with the bitboards in the `ChessBoard`, the index of the square is defined as it's position in the 64
/// bit bitboard. <br>
/// The index of the square is defined as `[0:7] = [h1:a1], [8:15] = [h2:a2] ... [56:63] = [h8:a8]`. <br>
/// Starting from `0` at `h1`, each rank increases the index by `8`, and each file increases the index by `1`.
///
/// @param coordinate The algebraic notation of the square.
/// @return Integer in the range [0,63] <br>
///         If the input is invalid, the function returns `333`.

int coordinateToIndex(const string& coordinate)
{
    int index;  // The index of the square.

    // If the notation is not in the correct format, return 333.
    if (coordinate.length()!=2 ||
            coordinate[0]<'a' || coordinate[0]>'h' ||
            coordinate[1]<'1' || coordinate[1]>'8') {
        return 333;
    }

    // Otherwise, convert the notation to an index.
    int file = 'h'-coordinate[0];
    int rank = 8*(coordinate[1]-'1');

    index = rank+file;

    return index;
}

//----------------------------------------------------------------------------------------------------------------------
// Converts index notation to chess algebraic notation.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Converts index notation to chess algebraic notation.
/// @param index The position of the square in the 64 bit bitboard.
/// @return The algebraic notation of the square, e.g., `a1`, `h8`, etc.
/// @see For further information on the index notation, see `coordinateToIndex()`

string indexToCoordinate(int index)
{
    string algebraic;

    int row = index/8+1;
    int column = index%8;

    switch (column) {
    case 0:algebraic += "h";
        break;
    case 1:algebraic += "g";
        break;
    case 2:algebraic += "f";
        break;
    case 3:algebraic += "e";
        break;
    case 4:algebraic += "d";
        break;
    case 5:algebraic += "c";
        break;
    case 6:algebraic += "b";
        break;
    case 7:algebraic += "a";
        break;
    default:algebraic += "x";
        break;
    }

    switch (row) {
    case 1:algebraic += "1";
        break;
    case 2:algebraic += "2";
        break;
    case 3:algebraic += "3";
        break;
    case 4:algebraic += "4";
        break;
    case 5:algebraic += "5";
        break;
    case 6:algebraic += "6";
        break;
    case 7:algebraic += "7";
        break;
    case 8:algebraic += "8";
        break;
    default:algebraic += "x";
        break;
    }

    return algebraic;
}

//----------------------------------------------------------------------------------------------------------------------
// Prints a vector of indices in algebraic notation.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Prints a vector of indices in algebraic notation.
///
/// Supplied with a vector of indices, the function uses `indexToCoordinate()` to convert the notation, then
/// prints the algebraic notation to the console. <br>
///
/// @param range The vector of indices to be printed.

void printCoordinates(const vector<int>& range)
{
    int printIndex = 0;
    while (printIndex<range.size()) {
        cout << indexToCoordinate(range[printIndex]) << " ";
        printIndex++;
    }
    cout << endl;
}

//----------------------------------------------------------------------------------------------------------------------
// Checks to see if a given index is in a given range.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Checks to see if a given index is in a given range.
///
/// @param range   The list of indices to search.
/// @param indexTo The index to search for.
///
/// @return True - the index is in the range. <br>
///         False - the index is not in the range.

bool rangeValidation(const vector<int>& range, const int indexTo)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {
        return true;
    }
    else {
        return false;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Removes any out of bounds indices from a range.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Removes any out of bounds indices from a range.
///
/// I was having issues with the diagonal range calculation supplying indices that were out of bounds
/// , so this is my quick fix.
///
/// @post vector `range` is modified to remove any out of bounds indices.
/// @param range The vector of indices to be cleaned.

void cleanRange(vector<int>& range)
{
    for (int i = 0; i<range.size(); i++) {
        if (range[i]<0 || range[i]>63) {
            range[i] = range.back();
            range.pop_back();
            i--;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Returns the file of a given index.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Returns the file of a given index.
///
/// @param index The index of the square.
/// @return `[a, b, c, d, e, f, g, h]` <br>
///         If the index supplied is out of bounds, the function returns `X`.

char getFile(const int index)
{
    int modulo = index%8;
    if (63>=index && index>=0) {
        switch (modulo) {
        case 0:return 'h';
        case 1:return 'g';
        case 2:return 'f';
        case 3:return 'e';
        case 4:return 'd';
        case 5:return 'c';
        case 6:return 'b';
        case 7:return 'a';
        default:return 'X';
        }
    }
    else {
        return 'X';
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Returns the rank of a given index.
///---------------------------------------------------------------------------------------------------------------------
/// @brief Returns the rank of a given index.
///
/// @param index The index of the square.

/// @return [1, 2, 3, 4, 5, 6, 7, 8] <br>
///         If the index supplied is out of bounds, the function returns `333`.

int getRank(int index)
{
    if (63>=index && index>=0) {
        return index/8+1;
    }
    else {
        return 333;
    }
}

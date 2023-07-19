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
/// To coincide with the bitboards in the `ChessBoard`, the index of the square is defined as it's position in the 64
/// bit bitboard. <br>
/// The index of the square is defined as `[0:7] = [h1:a1], [8:15] = [h2:a2] ... [56:63] = [h8:a8]`. <br>
/// Starting from `0` at `h1`, each rank increases the index by `8`, and each file increases the index by `1`.
/// @param coordinate The algebraic notation of the square.
/// @return The index of the square as defined by it's position in the 64 bit bitboard.

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

    int row = index/8 + 1;
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
/// The function takes each element of the vector one at a time, converts it to algebraic notation using
/// `indexToCoordinate()`, and prints it to the console. <br>
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
/// @brief The function's purpose
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @pre  precondition for function to work if needed
/// @post postcondition if the function changes argument data
///
/// @param param1 Description of the first parameter of the function.
/// @param param2 The second parameter, which follows @p param1.
///
/// @return Describe what the function returns. 
///         [a void function has no return]
///
/// @see place any citations here, such as http://website/
/// @note did anyone besides your instructor help you?
/// @warning Any Warnings relating to the use of this function
//------------------------------------------------------------------------------
bool rangeValidation(std::vector<int> range, int indexTo)
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
//----------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------  
/// @brief The function's purpose
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @pre  precondition for function to work if needed
/// @post postcondition if the function changes argument data
///
/// @param param1 Description of the first parameter of the function.
/// @param param2 The second parameter, which follows @p param1.
///
/// @return Describe what the function returns. 
///         [a void function has no return]
///
/// @see place any citations here, such as http://website/
/// @note did anyone besides your instructor help you?
/// @warning Any Warnings relating to the use of this function
//------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------  
/// @brief The function's purpose
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @pre  precondition for function to work if needed
/// @post postcondition if the function changes argument data
///
/// @param param1 Description of the first parameter of the function.
/// @param param2 The second parameter, which follows @p param1.
///
/// @return Describe what the function returns. 
///         [a void function has no return]
///
/// @see place any citations here, such as http://website/
/// @note did anyone besides your instructor help you?
/// @warning Any Warnings relating to the use of this function
//------------------------------------------------------------------------------
char getFile(int index)
{
    int modulo = index%8;
    switch (modulo) {
    case 0:return 'h';
    case 1:return 'g';
    case 2:return 'f';
    case 3:return 'e';
    case 4:return 'd';
    case 5:return 'c';
    case 6:return 'b';
    case 7:return 'a';
    default:return 'x';
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Returns the rank of a given index.
//----------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------  
/// @brief The function's purpose
///
/// Description of what the function does. This part may refer to the
/// parameters of the function, like @p param1 or @p param2.
///
/// @pre  precondition for function to work if needed
/// @post postcondition if the function changes argument data
///
/// @param param1 Description of the first parameter of the function.
/// @param param2 The second parameter, which follows @p param1.
///
/// @return Describe what the function returns. 
///         [a void function has no return]
///
/// @see place any citations here, such as http://website/
/// @note did anyone besides your instructor help you?
/// @warning Any Warnings relating to the use of this function
//------------------------------------------------------------------------------
int getRank(int index)
{
    return index/8 + 1;
}

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

/// @file   rank_and_file.cpp
/// @author de-Manzanares
/// @brief  Contains helper functions to check rank and file of a given index.

#include <vector>
#include <algorithm>

using namespace std;

bool rangeValidation(std::vector<int> range, int indexTo)
{
    if (find(range.begin(), range.end(), indexTo)!=range.end()) {
        return true;
    }
    else {
        return false;
    }
}

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

bool isInFile_A(int indexFrom)
{
    std::vector<int> file_A = {7, 15, 23, 31, 39, 47, 55, 63};
    if (find(file_A.begin(), file_A.end(), indexFrom)!=file_A.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool isInFile_H(int indexFrom)
{
    std::vector<int> file_H = {0, 8, 16, 24, 32, 40, 48, 56};
    if (find(file_H.begin(), file_H.end(), indexFrom)!=file_H.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool isInRank_2(int indexFrom)
{
    if (15>=indexFrom && indexFrom>=8) {
        return true;
    }
    else {
        return false;
    }
}

bool isInRank_7(int indexFrom)
{
    if (55>=indexFrom && indexFrom>=48) {
        return true;
    }
    else {
        return false;
    }
}

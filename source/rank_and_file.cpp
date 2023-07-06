#include <vector>
#include <algorithm>

bool rangeValidation(std::vector<int> range, int indexTo)
{
    if(find(range.begin(), range.end(), indexTo) != range.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool isInFile_A (int indexFrom)
{
    std::vector<int> file_A = {7, 15, 23, 31, 39, 47, 55, 63};
    if(find(file_A.begin(), file_A.end(), indexFrom) != file_A.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool isInFile_H (int indexFrom)
{
    std::vector<int> file_H = {0, 8, 16, 24, 32, 40, 48, 56};
    if(find(file_H.begin(), file_H.end(), indexFrom) != file_H.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool isInRank_2 (int indexFrom)
{
    if (15 >= indexFrom && indexFrom >= 8) {
        return true;
    }
    else {
        return false;
    }
}

bool isInRank_7 (int indexFrom)
{
    if (55 >= indexFrom && indexFrom >= 48) {
        return true;
    }
    else {
        return false;
    }
}
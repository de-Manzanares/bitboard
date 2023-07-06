#include <vector>
#include <algorithm>

bool rangeValidation(std::vector<int> range, int indexTo);

bool movePawn(char piece, int indexFrom, int indexTo)
{                                                                                

    // if (piece == 'p') {
    //     std::vecindexTor<int> range = {indexFrom - 8 * 1, indexFrom - 8 * 2};
    //     if(find(range.begin(), range.end(), indexTo) != range.end()) {
    //         valid = true;
    //     }
    //     else {
    //         valid = false;
    //     }
    // }
                                                                                 
    if (piece == 'P') {                                                          
        const int F_ONE = indexFrom + 8;
        const int F_TWO = indexFrom + 16;
        const int D_LEFT_ONE = indexFrom + 9;
        const int D_RIGHT_ONE = indexFrom + 7;


        if (15 >= indexFrom && indexFrom >= 8) {
            std::vector<int> range = {F_ONE, F_TWO, D_LEFT_ONE, D_RIGHT_ONE};

            if (rangeValidation(range, indexTo))
                return true;
        }


     //   // Check collision
     //   if (valid == true) {
     //       std::vecindexTor<char> path = {pieceSearch(piece, boards)
     //   }
    }
    return false;
}

bool rangeValidation(std::vector<int> range, int indexTo)
{
    if(find(range.begin(), range.end(), indexTo) != range.end()) {
       return true;
    }
    else {
        return false;
    }
}
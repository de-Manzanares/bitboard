#include <vector>
#include <algorithm>

int couldGo(char piece, int from, int to)                                        
{                                                                                
    bool valid;                                                                  
                                                                                 
    // if (piece == 'p') {                                                       
    //     from + 8 * 1  ;                                                       
    //     from + 8 * 2  ;                                                       
    // }                                                                         
    if (piece == 'p') {                                                          
        std::vector<int> range = {from - 8 * 1, from - 8 * 2};
        if(find(range.begin(), range.end(), to) != range.end()) {                
            valid = true;
        }                                                                        
        else {                                                                   
            valid = false;
        }                                                                        
    }                                                                            
                                                                                 
    if (piece == 'P') {                                                          
        std::vector<int> range = {from + 8 * 1, from + 8 * 2};
        if(find(range.begin(), range.end(), to) != range.end()) {                
            valid = true;
        }                                                                        
        else {                                                                   
            valid = false;
        }                                                                        
    }                                                                            
    return valid;                                                                
} 

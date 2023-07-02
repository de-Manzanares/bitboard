#include <vector>
#include <algorithm>
#include <cstdint>

char pieceSearch(int index,                                                      
                 uint64_t bitboard0, uint64_t bitboard1, uint64_t bitboard2,  uint64_t bitboard3,
                 uint64_t bitboard4, uint64_t bitboard5, uint64_t bitboard6,  uint64_t bitboard7,
                 uint64_t bitboard8, uint64_t bitboard9, uint64_t bitboard10, uint64_t bitboard11);

int couldGo(char piece, int from, int to)                                        
{                                                                                
    bool valid;                                                                  
                                                                                 
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
        const int F_ONE = from + 8;
        const int F_TWO = from + 16;
        std::vector<int> range = {F_ONE, F_TWO};

        // Check range
        if(find(range.begin(), range.end(), to) != range.end()) {                
            valid = true;
        }                                                                        
        else {                                                                   
            valid = false;
        }                                                                        
     //   // Check collision
     //   if (valid == true) {
     //       std::vector<char> path = {pieceSearch(F_ONE,                       
     //                                             black_pawn,                      
     //                                             black_night,                     
     //                                             black_bishop,                    
     //                                             black_rook,                      
     //                                             black_queen,                     
     //                                             black_king,                      
     //                                             white_Pawn,                      
     //                                             white_Night,                     
     //                                             white_Bishop,                    
     //                                             white_Rook,                      
     //                                             white_Queen,                     
     //                                             white_King)};
     //   }
    }                                                                            
    return valid;                                                                
} 

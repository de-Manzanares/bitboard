// include guard
#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct ChessBoard {
    uint64_t black_pawn   = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_night  = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_bishop = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_rook   = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_queen  = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t black_king   = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
    uint64_t white_Pawn   = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
    uint64_t white_Night  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
    uint64_t white_Bishop = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
    uint64_t white_Rook   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
    uint64_t white_Queen  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
    uint64_t white_King   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;    
};


void    printBitBoard   (ChessBoard& board);
int     coordinateIndex (const string& coordinate);
char    pieceSearch     (int index, const ChessBoard& board);
void    removePiece     (const char& piece, int index, ChessBoard& board);
void    addPiece        (const char& piece, int index, ChessBoard& board);
int     couldGo         (char pieceFrom, int indexFrom, int indexTo);

#endif // BITBOARDS_H

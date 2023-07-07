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

void    addPiece            (char piece, int index, ChessBoard& board);
void    addReplaceCommand   (stringstream& ss, ChessBoard& board);
int     coordinateIndex     (const string& coordinate);
void    fenCommand          (stringstream& ss, ChessBoard& board);
void    fenDecode           (string& fenIn, ChessBoard& board);
void    fenEncode           (ChessBoard& board);
bool    isInFile_A          (int indexFrom);
bool    isInFile_B          (int indexFrom);
bool    isInFile_C          (int indexFrom);
bool    isInFile_D          (int indexFrom);
bool    isInFile_E          (int indexFrom);
bool    isInFile_F          (int indexFrom);
bool    isInFile_G          (int indexFrom);
bool    isInFile_H          (int indexFrom);
bool    isInRank_2          (int indexFrom);
bool    isInRank_7          (int indexFrom);
void    moveCommand         (stringstream& ss, ChessBoard& board);
bool    movePawn            (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
bool    moveRook            (char pieceFrom, int indexFrom, int indexTo, ChessBoard& board);
char    pieceSearch         (int index, const ChessBoard& board);
void    printBitBoard       (ChessBoard& board);
bool    rangeValidation     (std::vector<int> range, int indexTo);
std::vector<int> squareSearch (char pieceFrom, int& flag, int& canMove , int indexTo, ChessBoard& board);
void    subtractPiece       (char piece, int index, ChessBoard& board);

#endif // BITBOARDS_H
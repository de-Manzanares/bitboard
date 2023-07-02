#include <iostream>
#include <string>

using namespace std;

void printBitBoard(uint64_t bitboard0  , 
                   uint64_t bitboard1  , 
                   uint64_t bitboard2  ,  
                   uint64_t bitboard3  ,
                   uint64_t bitboard4  , 
                   uint64_t bitboard5  ,
                   uint64_t bitboard6  ,
                   uint64_t bitboard7  ,
                   uint64_t bitboard8  ,
                   uint64_t bitboard9  ,
                   uint64_t bitboard10 ,
                   uint64_t bitboard11 )
{
    int counter = 0;
    int piece = 0;
    string line = "    +---+---+---+---+---+---+---+---+";

    cout << endl << line << endl << "    ";

    for (int i = 63; i >= 0; i--)
    {
        uint64_t mask = static_cast<uint64_t>(1) << i;

        cout << "| ";
                         if (bitboard0  & mask) { cout << "p" ; piece = 1;}

        if (piece == 0) {if (bitboard1  & mask) { cout << "n" ; piece = 1;}}
        if (piece == 0) {if (bitboard2  & mask) { cout << "b" ; piece = 1;}}
        if (piece == 0) {if (bitboard3  & mask) { cout << "r" ; piece = 1;}}
        if (piece == 0) {if (bitboard4  & mask) { cout << "q" ; piece = 1;}}
        if (piece == 0) {if (bitboard5  & mask) { cout << "k" ; piece = 1;}}
        if (piece == 0) {if (bitboard6  & mask) { cout << "P" ; piece = 1;}}
        if (piece == 0) {if (bitboard7  & mask) { cout << "N" ; piece = 1;}}
        if (piece == 0) {if (bitboard8  & mask) { cout << "B" ; piece = 1;}}
        if (piece == 0) {if (bitboard9  & mask) { cout << "R" ; piece = 1;}}
        if (piece == 0) {if (bitboard10 & mask) { cout << "Q" ; piece = 1;}}
        if (piece == 0) {if (bitboard11 & mask) { cout << "K" ; piece = 1;}}
        cout << " ";

        if (piece == 0) { cout << " ";}
        piece = 0;

        counter++;
        if (counter % 8 == 0) { cout << "|" << endl << line << endl << "    "; }
    }
    cout << endl;
}


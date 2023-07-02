#include <iostream>
#include <string>
#include "bitBoards.h"

using namespace std;

void printBitBoard(ChessBoard& board)
                   
{
    int counter = 0;
    int piece = 0;
    string line = "    +---+---+---+---+---+---+---+---+";

    cout << endl << line << endl << "    ";

    for (int i = 63; i >= 0; i--)
    {
        uint64_t mask = static_cast<uint64_t>(1) << i;

        cout << "| ";
                         if (board.black_pawn  & mask) { cout << "p" ; piece = 1;}

        if (piece == 0) {if (board.black_night  & mask) { cout << "n" ; piece = 1;}}
        if (piece == 0) {if (board.black_bishop & mask) { cout << "b" ; piece = 1;}}
        if (piece == 0) {if (board.black_rook   & mask) { cout << "r" ; piece = 1;}}
        if (piece == 0) {if (board.black_queen  & mask) { cout << "q" ; piece = 1;}}
        if (piece == 0) {if (board.black_king   & mask) { cout << "k" ; piece = 1;}}
        if (piece == 0) {if (board.white_Pawn   & mask) { cout << "P" ; piece = 1;}}
        if (piece == 0) {if (board.white_Night  & mask) { cout << "N" ; piece = 1;}}
        if (piece == 0) {if (board.white_Bishop & mask) { cout << "B" ; piece = 1;}}
        if (piece == 0) {if (board.white_Rook   & mask) { cout << "R" ; piece = 1;}}
        if (piece == 0) {if (board.white_Queen  & mask) { cout << "Q" ; piece = 1;}}
        if (piece == 0) {if (board.white_King   & mask) { cout << "K" ; piece = 1;}}
        cout << " ";

        if (piece == 0) { cout << " ";}
        piece = 0;

        counter++;
        if (counter % 8 == 0) { cout << "|" << endl << line << endl << "    "; }
    }
    cout << endl;
}


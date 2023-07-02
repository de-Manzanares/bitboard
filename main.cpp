#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void printBitBoard(uint64_t bitboard0, uint64_t bitboard1, uint64_t bitboard2,
                   uint64_t bitboard3, uint64_t bitboard4, uint64_t bitboard5,
                   uint64_t bitboard6, uint64_t bitboard7, uint64_t bitboard8,
                   uint64_t bitboard9, uint64_t bitboard10,
                   uint64_t bitboard11);

int coordinateIndex(const string& coordinate);

char pieceSearch(int index,
                 uint64_t bitboard0, uint64_t bitboard1, uint64_t bitboard2,
                 uint64_t bitboard3, uint64_t bitboard4, uint64_t bitboard5,
                 uint64_t bitboard6, uint64_t bitboard7, uint64_t bitboard8,
                 uint64_t bitboard9, uint64_t bitboard10,
                 uint64_t bitboard11);

void removePiece(const char& piece, int index,
                 uint64_t& bitboard0, uint64_t& bitboard1, uint64_t& bitboard2,
                 uint64_t& bitboard3, uint64_t& bitboard4, uint64_t& bitboard5,
                 uint64_t& bitboard6, uint64_t& bitboard7, uint64_t& bitboard8,
                 uint64_t& bitboard9, uint64_t& bitboard10,
                 uint64_t& bitboard11);

void addPiece(const char& piece, int index,
              uint64_t& bitboard0, uint64_t& bitboard1, uint64_t& bitboard2,
              uint64_t& bitboard3, uint64_t& bitboard4, uint64_t& bitboard5,
              uint64_t& bitboard6, uint64_t& bitboard7, uint64_t& bitboard8,
              uint64_t& bitboard9, uint64_t& bitboard10,
              uint64_t& bitboard11);

int couldGo(char pieceFrom, int indexFrom, int indexTo);

int main()
{

    string commandLine;

    // bitboards
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



    while (getline(cin, commandLine) && commandLine != "quit") {

        stringstream ss(commandLine);
        string command;
        ss >> command;

        if (command == "d") {
            printBitBoard(black_pawn, black_night, black_bishop, black_rook,
                          black_queen, black_king, white_Pawn, white_Night,
                          white_Bishop, white_Rook, white_Queen, white_King);
        }

        if (command == "mv") {
            string from;
            string to;

            if (!(ss >> from >> to)) {
                cout << endl;
                cout << "Invalid move command"
                     << endl << endl;
            }
            else {
                char pieceFrom;
                char pieceTo;
                int indexFrom = coordinateIndex(from);
                int indexTo   = coordinateIndex(to);

                if (indexFrom == 333 || indexTo == 333) {
                    cout << "Command must be in the form" << endl
                         << "mv <a-h><1-8> <a-h><1-8>" << endl << endl;
                }
                else {
                    pieceFrom = pieceSearch(    indexFrom,
                                                black_pawn,
                                                black_night,
                                                black_bishop,
                                                black_rook,
                                                black_queen,
                                                black_king,
                                                white_Pawn,
                                                white_Night,
                                                white_Bishop,
                                                white_Rook,
                                                white_Queen,
                                                white_King);

                    if (pieceFrom == 'E') {
                        cout << from << " is empty" << endl << endl;
                    }
                    else {

                        int couldGoHere;

                        couldGoHere = couldGo(pieceFrom,indexFrom,indexTo);

                        if (!(couldGoHere)) {
                            cout << "Invalid move command";
                            cout << endl << endl;

                        }
                        else {

                            cout << "Moving " << from << " to " << to
                                 << endl << endl;

                            removePiece(            pieceFrom,
                                                    indexFrom,
                                                    black_pawn,
                                                    black_night,
                                                    black_bishop,
                                                    black_rook,
                                                    black_queen,
                                                    black_king,
                                                    white_Pawn,
                                                    white_Night,
                                                    white_Bishop,
                                                    white_Rook,
                                                    white_Queen,
                                                    white_King);

                            pieceTo = pieceSearch(  indexTo,
                                                    black_pawn,
                                                    black_night,
                                                    black_bishop,
                                                    black_rook,
                                                    black_queen,
                                                    black_king,
                                                    white_Pawn,
                                                    white_Night,
                                                    white_Bishop,
                                                    white_Rook,
                                                    white_Queen,
                                                    white_King);

                            if (pieceTo == 'E') {
                                addPiece(           pieceFrom,
                                                    indexTo,
                                                    black_pawn,
                                                    black_night,
                                                    black_bishop,
                                                    black_rook,
                                                    black_queen,
                                                    black_king,
                                                    white_Pawn,
                                                    white_Night,
                                                    white_Bishop,
                                                    white_Rook,
                                                    white_Queen,
                                                    white_King);
                            }
                            else {
                                removePiece(        pieceTo,
                                                    indexTo,
                                                    black_pawn,
                                                    black_night,
                                                    black_bishop,
                                                    black_rook,
                                                    black_queen,
                                                    black_king,
                                                    white_Pawn,
                                                    white_Night,
                                                    white_Bishop,
                                                    white_Rook,
                                                    white_Queen,
                                                    white_King);

                                addPiece(           pieceFrom,
                                                    indexTo,
                                                    black_pawn,
                                                    black_night,
                                                    black_bishop,
                                                    black_rook,
                                                    black_queen,
                                                    black_king,
                                                    white_Pawn,
                                                    white_Night,
                                                    white_Bishop,
                                                    white_Rook,
                                                    white_Queen,
                                                    white_King);

                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

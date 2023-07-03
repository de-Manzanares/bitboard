#include <iostream>
#include <string>
#include <sstream>
#include "bitBoards.h"

using namespace std;

int main()
{

    string commandLine;
    ChessBoard board;

    while (getline(cin, commandLine) && commandLine != "quit") {
        stringstream ss(commandLine);
        string command;
        ss >> command;

        if (command == "add") {
            char pieceAdd;
            string to;

            if (!(ss >> pieceAdd >> to)) {
                cout << endl;
                cout << "Invalid add command"
                     << endl << endl;
            }
            else {
                int indexAdd = coordinateIndex(to);
                string validPieces = "KQRBNPkqrbnp";

                if (indexAdd == 333 || validPieces.find(pieceAdd) == string::npos) {
                    cout << "Command must be in the form" << endl
                         << "add <K|Q|R|B|N|P|k|q|r|b|n|p> <a-h><1-8>" << endl
                         << "for example: add Q f8" << endl << endl;
                }
                else {
                    char remove = pieceSearch(indexAdd, board);
                    if (remove == 'E') {
                        addPiece(pieceAdd, indexAdd, board);
                    }
                    else {
                        removePiece(remove, indexAdd, board);
                        addPiece(pieceAdd, indexAdd, board);
                    }
                }
            }
        }

        if (command == "d") {
            printBitBoard(board);
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
                    pieceFrom = pieceSearch(indexFrom, board);

                    if (pieceFrom == 'E') {
                        cout << from << " is empty" << endl << endl;
                    }
                    else {
                        cout << "Moving " << from << " to " << to
                             << endl << endl;
                        removePiece(pieceFrom, indexFrom, board);
                        pieceTo = pieceSearch(indexTo, board);

                        if (pieceTo == 'E') {
                            addPiece(pieceFrom, indexTo, board);
                        }
                        else {
                            removePiece(pieceTo, indexTo, board);
                            addPiece(pieceFrom, indexTo, board);

                        }
                    }
                }
            }
        }
    }
    return 0;
}


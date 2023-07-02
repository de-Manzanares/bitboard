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
                        int couldGoHere;
                        couldGoHere = couldGo(pieceFrom,indexFrom,indexTo);

                        if (!(couldGoHere)) {
                            cout << "Invalid move command";
                            cout << endl << endl;
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
    }
    return 0;
}

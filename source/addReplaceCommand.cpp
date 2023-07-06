#include <iostream>
#include <string>
#include <sstream>
#include "bitBoards.h"

void addReplaceCommand(stringstream& ss, ChessBoard& board)
{
    char pieceAdd;
    string to;

    if (!(ss >> pieceAdd >> to)) {
        cout << endl;
        cout << "Invalid add command"
             << endl << endl;
        return;
    }

    int index = coordinateIndex(to);
    string validPieces = "KQRBNPkqrbnp";

    if (index == 333 || validPieces.find(pieceAdd) == string::npos) {
        cout << "Command must be in the form" << endl
             << "add <K|Q|R|B|N|P|k|q|r|b|n|p> <a-h><1-8>" << endl
             << "for example: add Q f8" << endl << endl;
        return;
    }

    char pieceRemove = pieceSearch(index, board);

    cout << "Adding " << pieceAdd << " to " << to
         << endl << endl;

    if (pieceRemove == 'E') {
        addPiece(pieceAdd, index, board);
    }
    else {
        subtractPiece(pieceRemove, index, board);
        addPiece(pieceAdd, index, board);
    }
}
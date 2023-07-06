#include <iostream>
#include <string>
#include <sstream>
#include "bitBoards.h"

void moveCommand(stringstream& ss, ChessBoard& board)
{
    string from;
    string to;

    if (!(ss >> from >> to)) {
        cout << endl;
        cout << "Invalid move command"
             << endl << endl;
        return;
    }

    char pieceFrom;
    char pieceTo;
    int indexFrom = coordinateIndex(from);
    int indexTo   = coordinateIndex(to);

    if (indexFrom == 333 || indexTo == 333) {
        cout << "Command must be in the form" << endl
             << "mv <a-h><1-8> <a-h><1-8>" << endl << endl;
        return;
    }

    pieceFrom = pieceSearch(indexFrom, board);

    if (pieceFrom == 'E') {
        cout << from << " is empty" << endl << endl;
        return;
    }

    subtractPiece(pieceFrom, indexFrom, board);

     cout << "Moving " << from << " to " << to
          << endl << endl;

    pieceTo = pieceSearch(indexTo, board);

    if (pieceTo == 'E') {
        addPiece(pieceFrom, indexTo, board);
    }
    else
    {
        subtractPiece(pieceTo, indexTo, board);
        addPiece(pieceFrom, indexTo, board);
    }
}
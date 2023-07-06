#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "bitBoards.h"

void fenCommand(stringstream& ss, ChessBoard& board) {
    string direction;
    string fenIn;

    if (!(ss >> direction)) {
        cout << endl;
        cout << "Invalid FEN command"
             << endl << endl;
        return;
    }

    set<string> validDirection = {"in", "out"};

    if (validDirection.find(direction) != validDirection.end()) {

        if (direction == "in") {
            ss >> fenIn;
            fenDecode(fenIn, board);
        } else {
            fenEncode(board);
        }
    }
}
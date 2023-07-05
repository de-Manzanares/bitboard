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
            addReplaceCommand(ss, board);
        }

        if (command == "d") {
            printBitBoard(board);
        }

        if (command == "mv") {
            moveCommand(ss, board);
        }

        if (command == "fen") {
            fenCommand(ss,board);
        }
    }
    return 0;
}


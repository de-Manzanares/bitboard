#include <vector>
#include <string>
#include "bitBoards.h"

std::vector<int> squareSearch (char pieceFrom, int& flag, int& canMove , int indexTo, ChessBoard& board)
{
    string collisionPieces;
    string capturePieces;
    char pieceTo;

    if (pieceFrom == 'R') {
        collisionPieces = "KQRBNP";
        capturePieces = "kqrbnp";
    }
    if (pieceFrom == 'r') {
        collisionPieces = "kqrbnp";
        capturePieces = "KQRBNP";
    }

    if (!(canMove)) {canMove = false;}
    if (flag == 2) {canMove = false;}

    if (flag == 1) {
        pieceTo = pieceSearch(indexTo, board);
        if (collisionPieces.find(pieceTo) != string::npos) {flag = 0;}
        if (pieceTo == 'E') {flag = 1;}
        if (capturePieces.find(pieceTo) != string::npos) {flag = 2;}

        if (flag == 0) {canMove = false;}
        if (flag == 1) {canMove = true;}
        if (flag == 2) {canMove = true;}
    }

    return {flag, canMove};
}
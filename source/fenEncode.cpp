#include "bitBoards.h"

void fenEncode(ChessBoard& board)
{
    int counterLine = 0;
    int counterEmpty = 0;
    bool piecePrinted = false;
    bool nextRank = false;
    char piece = ' ';

    for (int i = 63; i >= 0; i--) {
        uint64_t mask = static_cast<uint64_t>(1) << i;

        if (board.black_pawn   & mask) { piece = 'p'; piecePrinted = true;}
        if (board.black_night  & mask) { piece = 'n'; piecePrinted = true;}
        if (board.black_bishop & mask) { piece = 'b'; piecePrinted = true;}
        if (board.black_rook   & mask) { piece = 'r'; piecePrinted = true;}
        if (board.black_queen  & mask) { piece = 'q'; piecePrinted = true;}
        if (board.black_king   & mask) { piece = 'k'; piecePrinted = true;}
        if (board.white_Pawn   & mask) { piece = 'P'; piecePrinted = true;}
        if (board.white_Night  & mask) { piece = 'N'; piecePrinted = true;}
        if (board.white_Bishop & mask) { piece = 'B'; piecePrinted = true;}
        if (board.white_Rook   & mask) { piece = 'R'; piecePrinted = true;}
        if (board.white_Queen  & mask) { piece = 'Q'; piecePrinted = true;}
        if (board.white_King   & mask) { piece = 'K'; piecePrinted = true;}

        if (!piecePrinted) {counterEmpty++;}

        counterLine++;
        nextRank = (counterLine % 8 == 0);

        if (counterEmpty > 0 && (piecePrinted || nextRank)) {
            cout << counterEmpty;
            counterEmpty = 0;
        }
        if (piecePrinted) {
            cout << piece;
            piecePrinted = false;
        }
        if (nextRank && i > 0){ cout << "/";}
    }
    if (counterEmpty > 0) {cout << counterEmpty;}
    cout << endl << endl;
}
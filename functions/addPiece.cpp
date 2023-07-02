#include <cstdint>

void addPiece(const char& piece, int index,
                 uint64_t& bitboard0, uint64_t& bitboard1, uint64_t& bitboard2,  uint64_t& bitboard3,
                 uint64_t& bitboard4, uint64_t& bitboard5, uint64_t& bitboard6,  uint64_t& bitboard7,
                 uint64_t& bitboard8, uint64_t& bitboard9, uint64_t& bitboard10, uint64_t& bitboard11)
{
    uint64_t mask = static_cast<uint64_t>(1) << index;

    if (piece == 'p') {bitboard0  = bitboard0  + mask;}
    if (piece == 'n') {bitboard1  = bitboard1  + mask;}
    if (piece == 'b') {bitboard2  = bitboard2  + mask;}
    if (piece == 'r') {bitboard3  = bitboard3  + mask;}
    if (piece == 'q') {bitboard4  = bitboard4  + mask;}
    if (piece == 'k') {bitboard5  = bitboard5  + mask;}
    if (piece == 'P') {bitboard6  = bitboard6  + mask;}
    if (piece == 'N') {bitboard7  = bitboard7  + mask;}
    if (piece == 'B') {bitboard8  = bitboard8  + mask;}
    if (piece == 'R') {bitboard9  = bitboard9  + mask;}
    if (piece == 'Q') {bitboard10 = bitboard10 + mask;}
    if (piece == 'K') {bitboard11 = bitboard11 + mask;}

}


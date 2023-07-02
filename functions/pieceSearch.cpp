#include <cstdint>

char pieceSearch(int index,
                 uint64_t bitboard0, uint64_t bitboard1, uint64_t bitboard2,  uint64_t bitboard3,
                 uint64_t bitboard4, uint64_t bitboard5, uint64_t bitboard6,  uint64_t bitboard7,
                 uint64_t bitboard8, uint64_t bitboard9, uint64_t bitboard10, uint64_t bitboard11)
{
    char piece = 'E';
    int found = 0;
    uint64_t mask = static_cast<uint64_t>(1) << index;

                     if (bitboard0  & mask) { piece = 'p' ; found = 1;}
    if (found == 0) {if (bitboard1  & mask) { piece = 'n' ; found = 1;}}
    if (found == 0) {if (bitboard2  & mask) { piece = 'b' ; found = 1;}}
    if (found == 0) {if (bitboard3  & mask) { piece = 'r' ; found = 1;}}
    if (found == 0) {if (bitboard4  & mask) { piece = 'q' ; found = 1;}}
    if (found == 0) {if (bitboard5  & mask) { piece = 'k' ; found = 1;}}
    if (found == 0) {if (bitboard6  & mask) { piece = 'P' ; found = 1;}}
    if (found == 0) {if (bitboard7  & mask) { piece = 'N' ; found = 1;}}
    if (found == 0) {if (bitboard8  & mask) { piece = 'B' ; found = 1;}}
    if (found == 0) {if (bitboard9  & mask) { piece = 'R' ; found = 1;}}
    if (found == 0) {if (bitboard10 & mask) { piece = 'Q' ; found = 1;}}
    if (found == 0) {if (bitboard11 & mask) { piece = 'K' ; found = 1;}}

    return piece;
}

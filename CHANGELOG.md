## 23.28

### Added

* Complete set of castling rules: the squares must be unoccupied, the king and rook must not
  have moved, the king must not be in check or move through/into check.

* Command `pam` to print, to a depth of 1, all moves for all pieces for both sides.

* Commands `infb` and `infw` to display a list of squares under the influence of all black and white pieces,
  respectively.

* Turn rule: black and white alternate turns.

### Fixed

* Knight move generation - it was not properly accounting for captures or collisions.

## 23.27

This week, I wrote my very first structures and my very first user defined functions in C++.

### Added

* Introduced new structure `ChessBoard` which includes all twelve bitboards. This allows for a more efficient and
  organized representation of the chessboard state. This is my first ever structure.


* Created header file ``bitBoards.h`` to improve organization and readability. This is my first ever header file.


* Added command to manually add a piece to the board. This is an intermediate step toward automatically prompting the
  user to select a piece for pawn promotion.


* New function ``fenEncode`` encodes the state of the board into a FEN string.
* New function ``fenDecode`` decodes FEN string to set the state of the board.
    * These functions are incomplete - they do not consider side to move, castling ability, en passant, or move count.


* New functions ``movePawn``, `moveKnight`, `moveBishop`, `moveRook`, `moveQueen`, and `moveKing` calculate the range
  of valid moves for the given piece, then check whether the target square of the move command is an element of that
  range.
    * these movement functions do not account for en passant, pawn promotion, castling, check, or checkmate.


* New functions `calculateMovesDiagonal`, `calculateMovesHorizontal`, `calculateMovesVertical` introduced to simplify
  move generation. They use recursive logic to continue searching in a given direction for a predetermined number of
  squares, or until `squareSearch` reports a collision or capture.


* New function ``squareSearch`` is a way to identify potential captures or collisions. It evaluates a square as
  empty, occupied by friendly, or occupied by hostile.

### Changed

* Refactored all pre-existing functions to utilize the new `ChessBoard` structure. This change has significantly
  improved the organization and readability of the code.

* Rewrote ``coordinateIndex()`` to fix issue with invalid input handling. The function now verifies the input string
  length, limiting valid input to two characters.

* Refactored main by writing command functions that include the pre-existing helper functions.

---

## 23.26

### Added

* Validation for coordinate inputs - limited to the format `<a-h><1-8>`.

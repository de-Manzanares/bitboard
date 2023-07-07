## 23.27

### Added

* Introduced new structure `ChessBoard` which includes all twelve bitboards. This allows for a more efficient and 
organized representation of the chessboard state. This is my first ever structure. 

* Created header file ``bitBoards.h`` to improve organization and readability. This is my first ever header file. 

* Added command to manually add a piece to the board. This is an intermediate step toward automatically prompting the user to select a piece for pawn promotion. 

* New function ``fenEncode`` encodes the state of the board into a FEN string. 
  * This function is incomplete - it does not encode side to move, castling ability, en passant, or move count. 

* New function ``fenDecode`` decodes FEN string to set the state of the board.
  * This function is incomplete - it does not decode side to move, castling ability, en passant, or move count.

* New functions ``movePawn`` and ``moveRook`` calculate the range of valid moves for the given piece, then check whether
the target square of the move command is an element of that range. 
  * ``movePawn`` is incomplete - it does not consider en passant or pawn promotion.
  * ``moveRook`` is incomplete - it does not consider castling rights. 

* New function ``squareSearch`` is a way to identify potential captures or collisions. It evaluates a square as 
empty, occupied by friendly, or occupied by hostile.

### Changed

* Refactored all pre-existing functions to utilize the new `ChessBoard` structure. This change has significantly improved the organization and readability of the code. 

* Rewrote ``coordinateIndex()`` to fix issue with invalid input handling. The function now verifies the input string length, limiting valid input to two characters. 

* Refactored main by writing command functions that include the pre-existing helper functions. 

---

## 23.26

### Added

* Validation for coordinate inputs - limited to the format `<a-h><1-8>`.

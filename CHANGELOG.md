### 23.27

Added

* Introduced new structure `ChessBoard` which includes all twelve bitboards. This allows for a more efficient and organized representation of the chessboard state.

* Created header file ``bitBoards.h`` to improve organization and readability.

* Added option to manually add a piece to the board. This is an intermediate step toward automatically prompting the user to select a piece for pawn promotion. 

Changed

* Refactored all pre-existing functions to utilize the new `ChessBoard` structure. This change has significantly improved the organization and readability of the code. 

* Rewrote ``coordinateIndex()`` to fix issue with invalid input handling. The function now verifies the input string length, limiting valid input to two characters. 

* Refactored main by writing command functions that include the pre-existing helper functions. 

---

### 23.26

Added

* Validation for coordinate inputs - limited to the format `<a-h><1-8>`.

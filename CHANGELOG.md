### 2023.07.03

Added

* Added option to manually add a piece to the board. This is an intermediate step toward automatically prompting the user to select a piece for pawn promotion. 

Changed

* Rewrote ``coordinateIndex()`` to fix issue with invalid input handling. The function now verifies the input string length, limiting valid input to two characters. 


---

### 2023.07.02 

Added

* Created header file ``bitBoards.h`` to improve organization and readability. 

* Introduced new structure `ChessBoard` which includes all twelve bitboards. This allows for a more efficient and organized representation of the chessboard state.

Changed

* Refactored all pre-existing functions to utilize the new `ChessBoard` structure. This change has significantly improved the organization and readability of the code. 


---

### 2023.07.01

Added

* Validation for coordinate inputs - limited to the format `<a-h><1-8>`.
* Started writing function `couldGo` to calculate the range of a possible move for a given chess piece. 
* Started writing rules for pawns in `couldGo` function.


---
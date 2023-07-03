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



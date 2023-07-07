## Overview

My goal, be it feasible or fantasy, is to write a chess engine from scratch. This bitboard is the 
first step. So, here we go! 

Using the command line interface (CLI) we can interact with the bitboard to move pieces 
and to display the state of the board. We can also import and export FEN strings. Currently, I am working on 
implementing rules.

If you'd like to play with the program without partial rules implemented, checkout the ``anarchy_chess`` branch.

![overview.gif](gif%2Foverview.gif)

---

## Installation

### Automated Installation Using CMake
Clone the repository
```angular2html
git clone https://github.com/de-Manzanares/bitboard.git
```

Move into the bitboard directory, then create and move into the build directory
```angular2html
cd bitboard
mkdir build
cd build
```

Run CMake, then compile
```angular2html
cmake ..
make
```

Launch the program
```angular2html
./bitboard
```

### Manual Installation Using g++
Clone the repository 
```angular2html
git clone https://github.com/de-Manzanares/bitboard.git
```

Move into the directory, then compile
```angular2html
cd bitboard
g++ -I include source/*.cpp -o bitboard
```

Launch the program 
```angular2html
./bitboard
```

---

## Commands
| Syntax                             | Description                    |
|------------------------------------|--------------------------------|
| ``d``                              | **d**isplay the board          |
| ``mv <FROM> <TO>``<sup>1</sup>     | **m**o**v**e a piece           |
| ``add <PIECE> <TO>``<sup>1</sup>   | **add** a piece to the board   |
| ``fen in <FEN>``<sup>2, 3, 4</sup> | set the state of the board     |
| ``fen out``<sup>2, 3</sup>         | display the state of the board |
| ``quit``                           | **quit** the program           |
<br>

<sup>1</sup> ``<FROM>`` and ``<TO>`` use [algebraic notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)). For example: ``mv e2 e4`` , ``add Q f8``

<sup>2</sup> [Forsyth-Edwards Notation](https://www.chess.com/terms/fen-chess) (FEN) is a line of text that contains all the 
necessary information to completely describe a game of chess. It describes where the pieces are, castling ability,
en passant targets, and half and full move count.  

<sup>3</sup> Currently, FEN implementation is incomplete. This program can interpret FEN strings insofar as piece placement, but does not consider side to move, 
castling ability, en passant, or move count. 

<sup>4</sup> For example: ``fen in 8/pp4pp/2pn1k2/3p1p2/3P1K2/6PP/PPP1B1P1/8``.

---

## Learn Chess

### Read the board

``K`` ``k`` ........ King

``Q`` ``q`` ........ Queen

``R`` ``r`` ........ Rook

``B`` ``b`` ........ Bishop

``N`` ``n`` ........ Knight

``P`` ``p`` ........ Pawn

### Cool resources

Gotham Chess: [How To Play Chess: The Ultimate Beginner Guide](https://www.youtube.com/watch?v=OCSbzArwB10)

Lichess: [Learn chess - by playing!](https://lichess.org/learn#/) 

---

## Contributions

If you have something to contribute, please do so! Feel free to email me at <git.in.touch@dmanz.org>

### Reporting Bugs
If you've found a bug, please open an issue on GitHub describing the problem. 

### Suggesting Features
If you have an idea for a new feature, please open an issue on GitHub describing your idea.

---

## To-do

### Priority
* Implement rules
  * Currently, there are partial rules for:
    * Pawn movement - need to add en passant and pawn promotion
  * Currently, there are no rules for:
    * Rook
    * Bishop
    * Knight
    * King 
    * Queen
* Finish FEN implementation by adding:
  * side to move, move counter, castling ability, en passant targets
* Implement portable game notation (PGN).

### Looking ahead
* Implement basic evaluation and decision-making.
* Implement UCI compatability.

### Little things
* Add an option to flip the board.
* Add an option to undo moves.
* Add an option to automatically display the board after each move.
* Change move function so that moving a piece to the square it currently occupies does not count as a move.
 
### Specific Stuff
* Divide ``ChessBoard`` structure into two colors. 


---

## License
Copyright (C) 2023 de-Manzanares

Without a license, this work would be under exclusive copyright by default. Express permission would be required 
in order to use, modify, or share this work. That's ridiculous! So, here ya go. 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
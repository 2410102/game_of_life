# game_of_life
The C++ code implementing Turing-complete Convey Game of Life.

The Game of Life has been invented by John Convey in 1970.
The main feature of this game is having no players; the gaming process is completely determined by the size of field and initial configuraion.
The game is Turing-complete. It means one may imitate any calculation by some configuration.
However, the computer memory is limited, and so this version is not Turing-complete and you have to enter the size of grid.

The rules are very simple. You should repeat it every generation:
* Every cell has got eight neighbours which are either dead or alive (one has to determine initial dead and alive cells);
* A dead cell with exactly three alive neighbours becomes alive;
* An alive cell with two or three alive neighbours survives; in other cases, it dies either from overpopulation or loneliness.
* If you get an empty ("completely dead") grid or a grid repeating older one, the game is over.

The Turing-completeness means you may even build a Game of Life in the Game of Life. However, it's extremely difficult.

// Medium Collection
// Amazon
/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?
*/

typedef struct {
    char** board;
    int n;
} TicTacToe;

/** Initialize your data structure here. */
TicTacToe* ticTacToeCreate(int n) {
    TicTacToe* game = (TicTacToe*) malloc (sizeof(TicTacToe));
    char** board = (char**) malloc (sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*) malloc (sizeof(char) * n);
    }
    game->board = board;
    game->n = n;
    return game;
}

/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    if (player == 1) {
        obj->board[row][col] = 'X';
        int horizontalWin = 1;
        int verticalWin = 1;
        int diagonalWin = 0;
        int rediagonalWin = 0;
        if (row == col) {
            diagonalWin = 1;
        }
        if (row + col == obj->n - 1) {
            rediagonalWin = 1;
        }
        for (int i = 0; i < obj->n; i++) {
            if (obj->board[i][col] != 'X') {
                horizontalWin = 0;
            }
            if (obj->board[row][i] != 'X') {
                verticalWin = 0;
            }
            if (row == col) {
                if (obj->board[i][i] != 'X') {
                    diagonalWin = 0;
                }
            }
            if (row + col == obj->n - 1) {
                if (obj->board[i][obj->n - 1 - i] != 'X') {
                    rediagonalWin = 0;
                }
            }
            if (!horizontalWin && !verticalWin && !diagonalWin && !rediagonalWin) {
                return 0;
            }
        }
        return 1;
    } else {
        obj->board[row][col] = 'O';
        int horizontalWin = 1;
        int verticalWin = 1;
        int diagonalWin = 0;
        int rediagonalWin = 0;
        if (row == col) {
            diagonalWin = 1;
        }
        if (row + col == obj->n - 1) {
            rediagonalWin = 1;
        }
        for (int i = 0; i < obj->n; i++) {
            if (obj->board[i][col] != 'O') {
                horizontalWin = 0;
            }
            if (obj->board[row][i] != 'O') {
                verticalWin = 0;
            }
            if (row == col) {
                if (obj->board[i][i] != 'O') {
                    diagonalWin = 0;
                }
            }
            if (row + col == obj->n - 1) {
                if (obj->board[i][obj->n - 1 - i] != 'O') {
                    rediagonalWin = 0;
                }
            }
            if (!horizontalWin && !verticalWin && !diagonalWin && !rediagonalWin) {
                return 0;
            }
        }
        return 2;
    }
}

void ticTacToeFree(TicTacToe* obj) {
    for (int i = 0; i < obj->n; i++) {
        free(obj->board[i]);
    }
    free(obj->board);
    free(obj);
}

/**
 * Your TicTacToe struct will be instantiated and called as such:
 * struct TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 * ticTacToeFree(obj);
 */

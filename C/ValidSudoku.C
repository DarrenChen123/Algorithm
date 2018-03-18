/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

bool isValidCol(char** board){
    int i, j;
    int arr[9];
    memset(arr, 0, 9 * sizeof(int));
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != '.')
                arr[board[i][j] - '0' - 1]++;
        }
        for(j = 0; j < 9; j++){
            if(arr[j] >= 2)
                return false;
        }
        memset(arr, 0, 9 * sizeof(int));
    }
    return true;
}
bool isValidRow(char** board){
    int i, j;
    int arr[9];
    memset(arr, 0, 9 * sizeof(int));
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[j][i] != '.')
                arr[board[j][i]- '0' -1]++;
        }
        for(j = 0; j < 9; j++){
            if(arr[j] >= 2)
            return false;
        }
        memset(arr, 0, 9 * sizeof(int));
    }
    return true;
}
bool isValidSqr(char** board){
    int i, j, n, m;
    int arr[9];
    memset(arr, 0, 9 * sizeof(int));
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            for(m = 0; m < 3; m++){
                for(n = 0; n < 3; n++){
                    if(board[i * 3 + m][j * 3 + n] != '.')
                        arr[board[i * 3 + m][j * 3 + n]- '0' - 1]++;
                }
            }
            for(m = 0; m < 9; m++){
                if(arr[m] >= 2)
                return false;
            }
            memset(arr, 0, 9*sizeof(int));
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    return isValidCol(board) && isValidRow(board) && isValidSqr(board);
}

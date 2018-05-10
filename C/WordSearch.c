/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

bool search(char** board, int boardRowSize, int boardColSize, int** visited, int row, int col, char* word, int index, int length) {
    if (row < 0 || row > boardRowSize - 1 || col < 0 || col > boardColSize - 1 || board[row][col] != word[index] || visited[row][col] || index > length - 1) {
        return false;
    }
    if (index == length - 1) {
        return true;
    }
    visited[row][col] = 1;
    if (search (board, boardRowSize, boardColSize, visited, row - 1, col, word, index + 1, length) ||
        search (board, boardRowSize, boardColSize, visited, row, col - 1, word, index + 1, length) ||
        search (board, boardRowSize, boardColSize, visited, row + 1, col, word, index + 1, length) ||
        search (board, boardRowSize, boardColSize, visited, row, col + 1, word, index + 1, length)) {
        return true;
    }
    visited[row][col] = 0;
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int length = strlen(word);
    if (boardRowSize * boardColSize < length) {
        return false;
    }
    int** visited = (int**) malloc (sizeof(int *) * boardRowSize);
    for (int i = 0; i < boardRowSize; i++) {
        int* column = (int *) malloc (sizeof(int) * boardColSize);
        memset(column, 0, sizeof(int) * boardColSize);
        visited[i] = column;
    }
    bool ret = false;
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == word[0]) {
                ret |= search(board, boardRowSize, boardColSize, visited, i, j, word, 0, length);
                if (ret) {
                    return ret;
                }
                for (int m = 0; m < boardRowSize; m++) {
                    memset(visited[m], 0, sizeof(int) * boardColSize);
                }
            }
        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        free(visited[i]);
    }
    free(visited);
    return ret;
}

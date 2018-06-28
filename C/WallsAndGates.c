// Subscription
// Bloomberg
/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example:

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
void visit(int** rooms, int roomsRowSize, int roomsColSize, int currentRow, int currentCol, int distance) {
    if (distance >= rooms[currentRow][currentCol]) {
        return;
    } else {
        rooms[currentRow][currentCol] = distance;
        if (currentRow > 0) {
            visit(rooms, roomsRowSize, roomsColSize, currentRow - 1, currentCol, distance + 1);
        }
        if (currentRow < roomsRowSize - 1) {
            visit(rooms, roomsRowSize, roomsColSize, currentRow + 1, currentCol, distance + 1);
        }
        if (currentCol > 0) {
            visit(rooms, roomsRowSize, roomsColSize, currentRow, currentCol - 1, distance + 1);
        }
        if (currentCol < roomsColSize - 1) {
            visit(rooms, roomsRowSize, roomsColSize, currentRow, currentCol + 1, distance + 1);
        }
    }
}
void wallsAndGates(int** rooms, int roomsRowSize, int roomsColSize) {
    if (roomsRowSize == 0 || roomsColSize == 0) {
        return;
    }
    for (int i = 0; i < roomsRowSize; i++) {
        for (int j = 0; j < roomsColSize; j++) {
            if (rooms[i][j] == 0) {
                if (i > 0) {
                    visit(rooms, roomsRowSize, roomsColSize, i - 1, j, 1);
                }
                if (i < roomsRowSize - 1) {
                    visit(rooms, roomsRowSize, roomsColSize, i + 1, j, 1);
                }
                if (j > 0) {
                    visit(rooms, roomsRowSize, roomsColSize, i, j - 1, 1);
                }
                if (j < roomsColSize - 1) {
                    visit(rooms, roomsRowSize, roomsColSize, i, j + 1, 1);
                }
            }
        }
    }
}

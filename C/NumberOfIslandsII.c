// Subscription
// Amazon
/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int* ids;
    int* szs;
    int m;
    int n;
    int cnt;
} UnionFind2D;

UnionFind2D * createSet(int m, int n) {
    UnionFind2D *obj = (UnionFind2D*) malloc (sizeof(UnionFind2D));
    obj->ids = (int*) malloc (sizeof(int) * m * n);
    obj->szs = (int*) malloc (sizeof(int) * m * n);
    obj->m = m;
    obj->n = n;
    obj->cnt = 0;
    for (int i = 0; i < m * n; i++) {
        obj->ids[i] = -1;
        obj->szs[i] = 1;
    }
    return obj;
}

int getIndex(int x, int y, UnionFind2D* obj) {
    return x * obj->n + y;
}

int size(UnionFind2D* obj) {
    return obj->cnt;
}

int id(int x, int y, UnionFind2D* obj) {
    if (x >= 0 && x < obj->m && y >= 0 && y< obj->n) {
        return obj->ids[getIndex(x, y, obj)];
    }
    return -1;
}

int add (int x, int y, UnionFind2D* obj) {
    int idx = getIndex(x, y, obj);
    obj->ids[idx] = idx;
    obj->szs[idx] = 1;
    obj->cnt++;
    return idx;
}

int root(int i, UnionFind2D* obj) {
    for (; i != obj->ids[i]; i = obj->ids[i]) {
        obj->ids[i] = obj->ids[obj->ids[i]];
    }
    return i;
}

bool find (int p, int q, UnionFind2D* obj) {
    return root(p, obj) == root(q, obj);
}

void unite (int p, int q, UnionFind2D* obj) {
    int i = root(p, obj);
    int j = root(q, obj);
    if(obj->szs[i] > obj->szs[j]) {
        int temp = i;
        i = j;
        j = temp;
    }
    obj->ids[i] = j;
    obj->szs[j] += obj->szs[i];
    obj->cnt--;
}

int* numIslands2(int m, int n, int** positions, int positionsRowSize, int positionsColSize, int* returnSize) {
    UnionFind2D *islands =  createSet(m, n);
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int* res = (int*) malloc (sizeof(int) * m * n);
    *returnSize = 0;
    for (int i = 0; i < positionsRowSize; i++) {
        int x = positions[i][0];
        int y = positions[i][1];
        int p = add(x, y, islands);
        for (int k = 0; k < 4; k++) {
            int q = id(x + dirs[k][0], y + dirs[k][1], islands);
            if (q >= 0 && !find(p, q, islands)) {
                unite(p, q, islands);
            }
        }
        res[(*returnSize)++] = size(islands);
    }
    return res;
}

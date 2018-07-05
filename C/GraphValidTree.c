// Subscription
// Amazon
/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/

int find (int * id, int index) {
    if (id[index] == index) {
        return index;
    } else {
        int ret = find(id, id[index]);
        id[index] = ret;
        return ret;
    }
}
void unionSet(int x, int y, int* id, int* sz) {
    int id1 = find(id, x);
    int id2 = find(id, y);
    if (id1 == id2) {
        return;
    } else {
        if (sz[id1] > sz[id2]) {
            id[id2] = id1;
            sz[id1] += sz[id2];
        } else {
            id[id1] = id2;
            sz[id2] += sz[id1];
        }
    }
}
bool validTree(int n, int** edges, int edgesRowSize, int edgesColSize) {
    int* id = (int *) malloc (sizeof(int) * n);
    int* sz = (int *) malloc (sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < edgesRowSize; i++) {
        int left = find(id, edges[i][0]);
        int right = find(id, edges[i][1]);
        if (left == right) {
            return false;
        } else {
            unionSet(left, right, id, sz);
        }
    }
    return edgesRowSize == n - 1;
}

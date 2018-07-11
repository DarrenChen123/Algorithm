// Subscription
// Yelp
/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

void visit(int **graph, int* visited, int index, int n) {
    if (visited[index]) {
        return;
    }
    visited[index] = true;
    for (int i = 0; i < n; i++) {
        if (graph[index][i]) {
            visit(graph, visited, i, n);
        }
    }
}

int countComponents(int n, int** edges, int edgesRowSize, int edgesColSize) {
    int** graph = (int**) malloc (sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc (sizeof(int) * n);
        memset(graph[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < edgesRowSize; i++) {
        graph[edges[i][0]][edges[i][1]] = graph[edges[i][1]][edges[i][0]] = 1;
    }
    int* visited = (int*) malloc (sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ret++;
            visit(graph, visited, i, n);
        }
    }
    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return ret;
}

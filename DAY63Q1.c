#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int adj[MAX][MAX], int n, int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
}

int main() {
    int n, s;

    scanf("%d", &n);

    int adj[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Call DFS
    dfs(adj, n, s);

    return 0;
}
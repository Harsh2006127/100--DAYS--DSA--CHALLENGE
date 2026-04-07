#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// DFS function to detect cycle
int dfs(int node, int adj[MAX][MAX], int visited[], int recStack[], int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int j = 0; j < n; j++) {
        if (adj[node][j] == 1) {

            // If not visited → DFS
            if (!visited[j]) {
                if (dfs(j, adj, visited, recStack, n))
                    return 1;
            }
            // If already in recursion stack → cycle
            else if (recStack[j]) {
                return 1;
            }
        }
    }

    recStack[node] = 0; // backtrack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // directed graph
    }

    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    // Check each component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
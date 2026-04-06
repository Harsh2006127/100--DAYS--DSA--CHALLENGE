#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int parent, bool visited[], int** adj, int* size) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, size))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int edges[1000][2];

    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Create adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* size = (int*)calloc(V, sizeof(int));

    // Count degrees
    for (int i = 0; i < E; i++) {
        size[edges[i][0]]++;
        size[edges[i][1]]++;
    }

    // Allocate memory
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0;
    }

    // Fill adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // DFS cycle detection
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool hasCycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size)) {
                hasCycle = true;
                break;
            }
        }
    }

    // Output
    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

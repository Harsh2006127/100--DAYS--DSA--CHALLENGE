#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int adj[MAX][MAX], int visited[], int n) {
    visited[node] = 1;

    for (int j = 0; j < n; j++) {
        if (adj[node][j] == 1 && !visited[j]) {
            dfs(j, adj, visited, n);
        }
    }

    push(node); // push after visiting all neighbors
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

    // Call DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, n);
        }
    }

    // Print topological order (reverse stack)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
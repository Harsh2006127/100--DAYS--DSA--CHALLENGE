#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function for Topological Sort
void topologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Create queue
    int queue[MAX], front = 0, rear = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        // Reduce indegree of neighbors
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}
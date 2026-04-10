#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Min Heap node
struct HeapNode {
    int vertex, dist;
};

// Create new adjacency node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Extract min
struct HeapNode extractMin(struct HeapNode heap[], int* size) {
    struct HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

// Insert into heap
void insertHeap(struct HeapNode heap[], int* size, int v, int dist) {
    int i = (*size)++;
    heap[i].vertex = v;
    heap[i].dist = dist;

    while (i != 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void dijkstra(struct Node* adj[], int n, int source) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    struct HeapNode heap[MAX];
    int size = 0;

    insertHeap(heap, &size, source, 0);

    while (size > 0) {
        struct HeapNode minNode = extractMin(heap, &size);
        int u = minNode.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(heap, &size, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("Distance from %d to %d = %d\n", source, i, dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // Directed graph
        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment for undirected
        /*
        struct Node* newNode2 = createNode(u, w);
        newNode2->next = adj[v];
        adj[v] = newNode2;
        */
    }

    int source;
    scanf("%d", &source);

    dijkstra(adj, n, source);

    return 0;
}
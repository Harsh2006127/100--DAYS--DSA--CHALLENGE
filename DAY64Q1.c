#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// BFS function
void bfs(struct Node* adj[], int n, int source) {
    int visited[n];

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(source);
    visited[source] = 1;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];

        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Directed graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment for undirected graph
        // struct Node* newNode2 = createNode(u);
        // newNode2->next = adj[v];
        // adj[v] = newNode2;
    }

    int source;
    scanf("%d", &source);

    // Perform BFS
    bfs(adj, n, source);

    return 0;
}
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value, int capacity) {
    if(size == capacity) {
        printf("Queue Full\n");
        return;
    }

    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

void dequeue(int capacity) {
    if(size == 0) {
        printf("Queue Empty\n");
        return;
    }

    front = (front + 1) % capacity;
    size--;
}

void display(int capacity) {
    int i, index = front;

    for(i = 0; i < size; i++) {
        printf("%d ", queue[index]);
        index = (index + 1) % capacity;
    }
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x, MAX);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        dequeue(MAX);
    }

    display(MAX);

    return 0;
}
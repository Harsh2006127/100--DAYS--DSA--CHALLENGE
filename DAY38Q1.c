#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front > 0) {
        front--;
        deque[front] = x;
    }
    else {
        printf("Deque Overflow\n");
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear < MAX - 1) {
        rear++;
        deque[rear] = x;
    }
    else {
        printf("Deque Overflow\n");
    }
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    return 0;
}
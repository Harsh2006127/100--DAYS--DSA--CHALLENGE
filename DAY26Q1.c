#include <stdio.h>
#include <stdlib.h>

/* Definition of Doubly Linked List Node */
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL, *newNode;

    /* Read number of nodes */
    scanf("%d", &n);

    /* Insert nodes */
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            /* First node */
            head = tail = newNode;
        } else {
            /* Insert at end */
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /* Traverse forward */
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
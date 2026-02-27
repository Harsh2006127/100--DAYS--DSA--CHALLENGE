#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Get length of linked list
int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move longer list ahead
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse both lists
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    int n, m, x;

    // First list
    scanf("%d", &n);
    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (!head1)
            head1 = tail1 = newNode(x);
        else {
            tail1->next = newNode(x);
            tail1 = tail1->next;
        }
    }

    // Second list
    scanf("%d", &m);
    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (!head2)
            head2 = tail2 = newNode(x);
        else {
            tail2->next = newNode(x);
            tail2 = tail2->next;
        }
    }

    struct Node* intersect = getIntersection(head1, head2);

    if (intersect)
        printf("%d", intersect->data);
    else
        printf("No Intersection");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check CBT
int isCBT(struct Node* root, int index, int total) {
    if (!root)
        return 1;

    if (index >= total)
        return 0;

    return isCBT(root->left, 2*index + 1, total) &&
           isCBT(root->right, 2*index + 2, total);
}

// Check Min Heap Property
int isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
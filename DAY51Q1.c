#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if(root == NULL)
        return createNode(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    if(root == NULL)
        return NULL;

    if(p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if(p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root; // split point → LCA
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}
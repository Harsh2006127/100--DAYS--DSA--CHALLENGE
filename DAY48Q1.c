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

int countLeaf(struct Node* root) {
    if(root == NULL)
        return 0;

    // if leaf node
    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1) {
        printf("0");
        return 0;
    }

    struct Node* nodes[1000];

    // Create nodes
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Link nodes
    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    printf("%d", countLeaf(nodes[0]));

    return 0;
}
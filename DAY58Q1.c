#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* build(int preorder[], int preStart, int preEnd,
                   int inorder[], int inStart, int inEnd) {
    
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    struct Node* root = createNode(preorder[preStart]);

    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == root->data)
            break;
    }

    int leftSize = index - inStart;

    // Left subtree
    root->left = build(preorder,
                       preStart + 1,
                       preStart + leftSize,
                       inorder,
                       inStart,
                       index - 1);

    // Right subtree
    root->right = build(preorder,
                        preStart + leftSize + 1,
                        preEnd,
                        inorder,
                        index + 1,
                        inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000    ];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = build(preorder, 0, n - 1,
                              inorder, 0, n - 1);

    postorder(root);

    return 0;
}
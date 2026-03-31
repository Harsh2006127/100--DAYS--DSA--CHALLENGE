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

struct Node* build(int inorder[], int inStart, int inEnd,
                   int postorder[], int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == root->data)
            break;
    }

    root->right = build(inorder, index + 1, inEnd,
                        postorder, postIndex);

    root->left = build(inorder, inStart, index - 1,
                       postorder, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[1000], postorder[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, 0, n - 1,
                             postorder, &postIndex);

    preorder(root);

    return 0;
}
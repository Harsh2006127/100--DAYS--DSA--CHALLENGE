#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top != -1)
            top--;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int p, q;
    int log1[1000], log2[1000];

    // Read first log
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read second log
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // Append remaining elements from log1
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // Append remaining elements from log2
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
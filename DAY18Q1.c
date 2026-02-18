#include <stdio.h>

int main() {
    int n, k;
    int arr[1000], temp[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;

    int index = 0;
    for (int i = n - k; i < n; i++) {
        temp[index++] = arr[i];
    }

    for (int i = 0; i < n - k; i++) {
        temp[index++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
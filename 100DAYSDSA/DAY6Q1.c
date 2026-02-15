#include <stdio.h>

int main() {
    int n;
    int arr[1000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) return 0;  

    int i = 0; 

    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    for(int k = 0; k <= i; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int map[200001] = {0};
    int offset = 100000;

    int prefixSum = 0;
    long long count = 0;

    map[offset] = 1; 

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += map[prefixSum + offset];
        map[prefixSum + offset]++;
    }

    printf("%lld", count);
    return 0;
}
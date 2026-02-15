#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];  
    scanf("%s", str);

    int n = strlen(str);
    int left = 0, right = n - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("%s", str);

    return 0;
}
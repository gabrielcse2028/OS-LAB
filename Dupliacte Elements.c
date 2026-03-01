#include <stdio.h>

int main() {
    int a[100], n, i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    printf("Duplicate element found : ");
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                printf("%d ", a[i]);
                break;
            }
        }
    }

    return 0;
}

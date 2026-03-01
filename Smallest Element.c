#include <stdio.h>

int main() {
    int a[100], n, i;
    int smallest, pos;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    smallest = a[0];
    pos = 0;


    for(i = 1; i < n; i++) {
        if(a[i] < smallest) {
            smallest = a[i];
            pos = i;
        }
    }


    printf("\nSmallest element: %d", smallest);
    printf("\nFound at position: %d\n", pos + 1);

    return 0;
}

#include <stdio.h>


int linearsearch(int a[], int n, int ele) {
    for(int i = 0; i < n; i++) {
        if (a[i] == ele) {
            return i;
        }
    }
    return -1;
}

int Binarysearch(int a[], int n, int ele) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] == ele)
            return mid;
        else if(ele < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int a[10], i, ele, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the Elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the search element: ");
    scanf("%d", &ele);


    int pos = linearsearch(a, n, ele);
    printf("\nUsing Linear Search:\n");
    if(pos == -1)
        printf("Search element not found\n");
    else
        printf("Element found at position %d\n", pos + 1);


    pos = Binarysearch(a, n, ele);
    printf("\nUsing Binary Search:\n");
    if(pos == -1)
        printf("Search element not found\n");
    else
        printf("Element found at position %d\n", pos + 1);

    return 0;
}

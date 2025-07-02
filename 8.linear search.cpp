#include <stdio.h>

int main() {
    int arr[100], n, i, search, found = 0;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number to search
    printf("Enter number to search: ");
    scanf("%d", &search);

    // Linear search logic
    for(i = 0; i < n; i++) {
        if(arr[i] == search) {
            printf("Number found at position %d (index %d)\n", i+1, i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Number not found in the array.\n");
    }

    return 0;
}


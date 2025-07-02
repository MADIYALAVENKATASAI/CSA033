#include <stdio.h>

int main() {
    int arr[100], n, i, search, first, last, middle;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search) {
            printf("Number found at position %d (index %d)\n", middle + 1, middle);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }

    if (first > last)
        printf("Number not found in the array.\n");

    return 0;
}


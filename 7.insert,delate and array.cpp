#include <stdio.h>

int main() {
    int arr[100], n, i, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position.\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                for(i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                printf("Element inserted.\n");
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position.\n");
                    break;
                }
                for(i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted.\n");
                break;

            case 3:
                printf("Array elements: ");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}


#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int value) {
    int key = value % SIZE;
    int i = 0;

    while(hashTable[(key + i) % SIZE] != -1) {
        i++;
        if(i == SIZE) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[(key + i) % SIZE] = value;
    printf("%d inserted at index %d\n", value, (key + i) % SIZE);
}

void display() {
    printf("Hash Table:\n");
    for(int i = 0; i < SIZE; i++)
        printf("Index %d: %d\n", i, hashTable[i]);
}

int main() {
    int choice, value;

    initialize();

    while(1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node **head, int value) {
    struct Node *temp = *head, *prev = NULL;

    if(temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node *head = NULL;
    int choice, value;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


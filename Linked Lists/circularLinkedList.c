#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the rear of the list
struct Node* insertRear(struct Node* last, int data) {
    if (last == NULL) {
        struct Node* newNode = createNode(data);
        newNode->next = newNode; // Points to itself to make it circular
        return newNode;
    }
    struct Node* newNode = createNode(data);
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

// Function to insert at the front of the list
struct Node* insertFront(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode; // Points to itself to make it circular
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to insert at a particular node
struct Node* insertAtNode(struct Node* last, int data, int position) {
    if (last == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = last->next;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == last->next) {
            printf("Position out of range!\n");
            return last;
        }
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) {
        last = newNode;
    }
    return last;
}

// Function to delete from the rear of the list
struct Node* deleteRear(struct Node* last) {
    if (last == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (last->next == last) {
        free(last);
        return NULL;
    }
    struct Node* temp = last->next;
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    return temp;
}

// Function to delete from the front of the list
struct Node* deleteFront(struct Node* last) {
    if (last == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (last->next == last) {
        free(last);
        return NULL;
    }
    struct Node* temp = last->next;
    last->next = temp->next;
    free(temp);
    return last;
}

// Function to delete at a particular node
struct Node* deleteAtNode(struct Node* last, int position) {
    if (last == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = last->next;
    struct Node* prev = last;
    for (int i = 0; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == last->next) {
            printf("Position out of range!\n");
            return last;
        }
    }
    prev->next = temp->next;
    if (temp == last) {
        last = prev;
    }
    free(temp);
    return last;
}

// Function to print the circular linked list
void printList(struct Node* last) {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Main function
int main() {
    struct Node* last = NULL;
    int choice, data, position;

    printf("\nCircular Linked List Operations:\n");
    printf("1. Insert at rear\n");
    printf("2. Insert at front\n");
    printf("3. Insert at a particular position\n");
    printf("4. Delete from rear\n");
    printf("5. Delete from front\n");
    printf("6. Delete at a particular position\n");
    printf("7. Print list\n");
    printf("8. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                last = insertRear(last, data);
                break;
            case 2:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                last = insertFront(last, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                last = insertAtNode(last, data, position);
                break;
            case 4:
                last = deleteRear(last);
                break;
            case 5:
                last = deleteFront(last);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                last = deleteAtNode(last, position);
                break;
            case 7:
                printf("Circular linked list: ");
                printList(last);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
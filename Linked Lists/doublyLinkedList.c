#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the front of the list
struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to delete the front node of the list
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = head->next;
    if (temp != NULL) {
        temp->prev = NULL;
    }
    free(head);
    return temp;
}

// Function to delete the end node of the list
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    if (temp == head) {
        head = NULL;
    }
    free(temp);
    return head;
}

// Function to print the list from the front
void printForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the list from the end
void printBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    printf("\nDoubly Linked List Operations:\n");
    printf("1. Insert at front\n");
    printf("2. Insert at end\n");
    printf("3. Delete from front\n");
    printf("4. Delete from end\n");
    printf("5. Print list forward\n");
    printf("6. Print list backward\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteEnd(head);
                break;
            case 5:
                printf("List forward: ");
                printForward(head);
                break;
            case 6:
                printf("List backward: ");
                printBackward(head);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
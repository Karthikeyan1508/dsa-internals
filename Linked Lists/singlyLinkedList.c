#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *link;
};

// Global variable for the start of the linked list
struct node *start = NULL;

// Function prototypes
void insert_front();
void insert_end();
void delete_front();
void delete_rear();
void display();
void insert_at_position(int data, int position);
void delete_at_position(int position);

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_front();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                {
                    int data, position;
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter position to insert: ");
                    scanf("%d", &position);
                    insert_at_position(data, position);
                }
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_rear();
                break;
            case 6:
                {
                    int position;
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    delete_at_position(position);
                }
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert a node at the front of the linked list
void insert_front() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->link = start;
    printf("Enter the value: ");
    scanf("%d", &newnode->info);
    start = newnode;
}

// Function to insert a node at the end of the linked list
void insert_end() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &newnode->info);
    newnode->link = NULL;
    if (start == NULL)
        start = newnode;
    else {
        struct node *temp = start;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newnode;
    }
}

// Function to insert a node at any position in the linked list
void insert_at_position(int data, int position) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = data;

    if (position == 0) {
        newnode->link = start;
        start = newnode;
        return;
    }

    struct node *temp = start;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->link = temp->link;
    temp->link = newnode;
}

// Function to delete a node from the front of the linked list
void delete_front() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    start = start->link;
    printf("Deleted node is %d\n", temp->info);
    free(temp);
}

// Function to delete a node from the rear of the linked list
void delete_rear() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start->link == NULL) {
        printf("Deleted node is %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }
    struct node *temp = start, *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    printf("Deleted node is %d\n", temp->info);
    free(temp);
}

// Function to delete a node from any position in the linked list
void delete_at_position(int position) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        struct node *temp = start;
        start = start->link;
        printf("Deleted node is %d\n", temp->info);
        free(temp);
        return;
    }
    struct node *temp = start, *prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    prev->link = temp->link;
    printf("Deleted node is %d\n", temp->info);
    free(temp);
}

// Function to display the linked list
void display() {
    struct node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

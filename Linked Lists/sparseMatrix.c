#include<stdio.h>
#include<stdlib.h>

// Node structure to represent linked list
struct Node {
    int row;
    int col;
    int data;
    struct Node* next;
};

// Function to create a new node
void create_new_node(struct Node** p, int row_index,
                     int col_index, int x) {
    struct Node* temp = *p;
    struct Node* r;

    // If linked list is empty then create the first node and assign value.
    if (temp == NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }

    // If linked list is already created then append the newly created node
    else {
        while (temp->next != NULL)
            temp = temp->next;

        r = (struct Node*)malloc(sizeof(struct Node));
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

// Function to print contents of linked list starting from start
void printList(struct Node* start) {
    struct Node* ptr = start;
    printf("row_position:");
    while (ptr != NULL) {
        printf("%d ", ptr->row);
        ptr = ptr->next;
    }
    printf("\n");
    printf("column_position:");

    ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->col);
        ptr = ptr->next;
    }
    printf("\n");
    printf("Value:");
    ptr = start;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Driver Code
int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamic allocation of 2D array for sparse matrix
    int** sparseMatrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        sparseMatrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    // Creating head/first node of list as NULL
    struct Node* first = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Pass only those values which are non-zero
            if (sparseMatrix[i][j] != 0)
                create_new_node(&first, i, j, sparseMatrix[i][j]);
        }
    }
    printList(first);

    // Deallocating memory for 2D array
    for (int i = 0; i < rows; ++i) {
        free(sparseMatrix[i]);
    }
    free(sparseMatrix);

    return 0;
}

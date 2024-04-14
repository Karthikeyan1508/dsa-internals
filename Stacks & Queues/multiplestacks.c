#include <stdio.h>

#define STACK_SIZE 100
#define MAX_STACK 10 // stack number + 1
#define element int // change the type if needed

element stack[STACK_SIZE];
int top[MAX_STACK];
int boundary[MAX_STACK];
int n; // n < MAX_STACK (number of stacks)

// Initialize stack boundaries
void initialize_stacks() {
    top[0] = boundary[0] = -1;
    for (int i = 1; i < n; i++) {
        top[i] = boundary[i] = (STACK_SIZE / n) * i;
    }
    boundary[n] = STACK_SIZE - 1;
}

// Function to check if the stack is full
int stack_full(int i) {
    return top[i] == boundary[i + 1];
}

// Function to check if the stack is empty
int stack_empty(int i) {
    return top[i] == boundary[i];
}

// Push operation
void push(int i, element item) {
    if (stack_full(i)) {
        printf("Stack %d is full!\n", i);
        return;
    }
    stack[++top[i]] = item;
}

// Pop operation
element pop(int i) {
    if (stack_empty(i)) {
        printf("Stack %d is empty!\n", i);
        return -1; // Return some default value or handle error as per requirement
    }
    return stack[top[i]--];
}

int main() {
    n = 3; // Example: Create 3 stacks
    initialize_stacks();

    // Pushing elements into different stacks
    push(1, 10);
    push(1, 20);
    push(2, 30);

    // Popping elements from different stacks
    printf("Popped from stack 1: %d\n", pop(1));
    printf("Popped from stack 2: %d\n", pop(2));
    printf("Popped from stack 1: %d\n", pop(1));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a single term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

// Function to create a new term
Term* createTerm(int coef, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a new term to the polynomial
void addTerm(Term** poly, int coef, int exp) {
    Term* newTerm = createTerm(coef, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
    } else {
        while (poly != NULL) {
            printf("%dx^%d ", poly->coefficient, poly->exponent);
            if (poly->next != NULL) {
                printf("+ ");
            }
            poly = poly->next;
        }
        printf("\n");
    }
}

int main() {
    Term* polynomial = NULL;

    // Adding terms to the polynomial
    addTerm(&polynomial, 5, 2);
    addTerm(&polynomial, -3, 1);
    addTerm(&polynomial, 2, 0);

    // Displaying the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}

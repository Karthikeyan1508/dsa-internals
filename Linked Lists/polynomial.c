//Add two polynomials

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

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coef = 0, exp = 0;
        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exponent == poly2->exponent) {
                coef = poly1->coefficient + poly2->coefficient;
                exp = poly1->exponent;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->exponent > poly2->exponent) {
                coef = poly1->coefficient;
                exp = poly1->exponent;
                poly1 = poly1->next;
            } else {
                coef = poly2->coefficient;
                exp = poly2->exponent;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            coef = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        } else {
            coef = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        addTerm(&result, coef, exp);
    }
    return result;
}

int main() {
    Term* polynomial1 = NULL;
    Term* polynomial2 = NULL;

    // Adding terms to the first polynomial
    addTerm(&polynomial1, 5, 2);
    addTerm(&polynomial1, -3, 1);
    addTerm(&polynomial1, 2, 0);

    // Adding terms to the second polynomial
    addTerm(&polynomial2, 3, 2);
    addTerm(&polynomial2, 4, 1);
    addTerm(&polynomial2, 1, 0);

    // Displaying the first polynomial
    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);

    // Displaying the second polynomial
    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    // Adding the two polynomials
    Term* sum = addPolynomials(polynomial1, polynomial2);

    // Displaying the result
    printf("Sum: ");
    displayPolynomial(sum);

    return 0;
}

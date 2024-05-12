#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LEN 100

// Structure to represent a node in the DAG
struct Node {
    int ptr;
    int leftPtr;
    int rightPtr;
    char label[MAX_EXPR_LEN];
};

// Function to check if a character is an operand (variable)
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to construct the DAG for the given expression
void constructDAG(char *expression, struct Node *dag) {
    int n = strlen(expression);
    int ptr = 0; // Pointer index for the next node in the DAG

    for (int i = 0; i < n; i++) {
        // If the character is an operand, create a node for it
        if (isOperand(expression[i])) {
            dag[ptr].ptr = ptr;
            dag[ptr].leftPtr = -1;
            dag[ptr].rightPtr = -1;
            dag[ptr].label[0] = expression[i];
            dag[ptr].label[1] = '\0';
            ptr++;
        }
        // If the character is an operator, create a node for it
        else if (isOperator(expression[i])) {
            dag[ptr].ptr = ptr;
            dag[ptr].rightPtr = dag[ptr - 1].ptr; // Set right pointer to the current operand
            dag[ptr].leftPtr = dag[ptr - 2].ptr; // Set left pointer to the previous operand
            dag[ptr].label[0] = expression[i];
            dag[ptr].label[1] = '\0';
            ptr++;
        }
    }
}

// Function to display the constructed DAG
void displayDAG(struct Node *dag, int size) {
    printf("DAG FOR GIVEN EXPRESSION\n");
    printf("PTR\tLEFT PTR\tRIGHT PTR\tLABEL\n");
    for (int i = 0; i < size; i++) {
        if (dag[i].ptr == -1) {
            continue; // Skip printing if pointer is -1 (uninitialized node)
        }
        printf("%d\t%d\t\t%d\t\t%s\n", dag[i].ptr, dag[i].leftPtr, dag[i].rightPtr, dag[i].label);
    }
}

int main() {
    char expression[MAX_EXPR_LEN];

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);
    // expression[strcspn(expression, "\n")] = '\0'; // Remove newline character

    struct Node dag[MAX_EXPR_LEN]; // Array to store nodes of the DAG
    for (int i = 0; i < MAX_EXPR_LEN; i++) {
        dag[i].ptr = -1; // Initialize pointers to -1
    }

    constructDAG(expression, dag);
    displayDAG(dag, strlen(expression));

    return 0;
}

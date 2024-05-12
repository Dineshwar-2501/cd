#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

void analyzeDataFlow(const char *expr) {
    int len = strlen(expr);
    int i;

    printf("Variables used in the expression:\n");
    for (i = 0; i < len; i++) {
        if (isalpha(expr[i])) {
            printf("%c is live at %s", expr[i],expr); // Print the operation
        }
    }

    printf("\nOperations performed in the expression:\n");
    for (i = 0; i < len; i++) {
        if (!isalpha(expr[i]) && !isspace(expr[i])) {
            printf("%c is live at %s", expr[i],expr); // Print the operation
        }
    }
}

int main() {
    char expression[MAX_EXPR_LEN];

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);
    

    analyzeDataFlow(expression);

    return 0;
}
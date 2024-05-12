#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int x = 0, n, i = 0, j = 0;
    void *mypointer, *address[5];
    int c;
    char Search, Array2[15], Array3[15];

    printf("Input the expression ending with $ sign:");
    while ((c = getchar()) != '$' && i < 14) {
        Array2[i] = c;
        i++;
    }
    n = i - 1;
    printf("Given Expression:");
    for (i = 0; i <= n; i++) {
        printf("%c", Array2[i]);
    }
    printf("\nSymbol Table display\n");
    printf("Symbol\t \t addr\t \t type\n");

    while (j <= n) {
        c = Array2[j];
        if (isalpha(c)) {
            mypointer = malloc(sizeof(char));
            printf("\n%c \t %p \t identifier\n", c, mypointer);
            j++;
        } else {
            char ch = c;
            if (ch == '+' || ch == '-' || ch == '*' || ch == '='|| ch == '/') {
                mypointer = malloc(sizeof(char));
                printf("\n %c \t %p \t operator\n", ch, mypointer);
                j++;
            }
        }
    }
    return 0;
}
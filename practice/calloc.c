#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *myArray = (int*) calloc(n, sizeof(int)); // Use sizeof(int) instead of sizeof(n)
    if (myArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d \t", myArray[i]);
    }

    free(myArray); // Free allocated memory

    return 0;
}

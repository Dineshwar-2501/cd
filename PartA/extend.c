#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Allocate memory for array A
    int *A = (int*)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed for array A.\n");
        return 1;
    }

    // Initialize array A
    for (int i = 0; i < n; i++) {
        A[i] = i+1 ;
    }

    // Reallocate memory for array B (double the size of array A)
    int *B = (int*)realloc(A, 2 * n * sizeof(int));
    if (B == NULL) {
        printf("Memory reallocation failed for array B.\n");
        free(A); // Free the previously allocated memory for array A
        return 1;
    }

    // Print the addresses and elements of array B
    printf("Previous address: %p\n", A);
    printf("New address: %p\n", B);
    printf("Elements of array B:\n");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d\n", B[i]);
    }

    // Free the allocated memory for array B
    free(B);

    return 0;
}

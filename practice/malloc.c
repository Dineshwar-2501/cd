#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *myArray = (int*) malloc(n * sizeof(int));
    if (myArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        myArray[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d \t", myArray[i]);
    }

    free(myArray); 
    myArray = NULL;
    if(myArray == NULL) {
        printf("Memory is freed.\n");
    }

   return 0;
}

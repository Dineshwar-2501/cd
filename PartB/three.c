#include <stdio.h>
#include <string.h>

struct Operation {
    char lhs;
    char rhs[20];
} op[10], pr[10];

int main() {
    int n, z = 0;
    char temp, t, *p, *l, *tem;
    
    printf("Enter the number of values: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Enter the value of left: ");
        scanf(" %c", &op[i].lhs);
        printf("Enter the value of right: ");
        scanf("%s", op[i].rhs);
    }

    printf("\nIntermediate Code:\n");
    for (int i = 0; i < n; i++) {
        printf("%c=%s\n", op[i].lhs, op[i].rhs);
    }

    // Dead Code Elimination
    for (int i = 0; i < n - 1; i++) {
        temp = op[i].lhs;
        for (int j = 0; j < n; j++) {
            p = strchr(op[j].rhs, temp);
            if (p) {
                pr[z] = op[i];
                z++;
            }
        }
    }
    pr[z] = op[n - 1];
    z++;

    printf("\nAfter Dead Code Elimination:\n");
    for (int k = 0; k < z; k++) {
        printf("%c=%s\n", pr[k].lhs, pr[k].rhs);
    }

    // Sub-expression Elimination
    for (int m = 0; m < z; m++) {
        tem = pr[m].rhs;
        for (int j = m + 1; j < z; j++) {
            p = strstr(tem, pr[j].rhs);
            if (p) {
                t = pr[j].lhs;
                pr[j].lhs = pr[m].lhs;
                for (int i = 0; i < z; i++) {
                    l = strchr(pr[i].rhs, t);
                    if (l) {
                        pr[i].rhs[l - pr[i].rhs] = pr[m].lhs;
                    }
                }
            }
        }
    }

    printf("\nEliminate Common Expression:\n");
    for (int i = 0; i < z; i++) {
        printf("%c=%s\n", pr[i].lhs, pr[i].rhs);
    }

    // Duplicate Production Elimination
    for (int i = 0; i < z; i++) {
        for (int j = i + 1; j < z; j++) {
            if (pr[i].lhs == pr[j].lhs && strcmp(pr[i].rhs, pr[j].rhs) == 0) {
                pr[i].lhs = '\0';
                strcpy(pr[i].rhs, "\0");
            }
        }
    }

    printf("\nOptimized Code:\n");
    for (int i = 0; i < z; i++) {
        if (pr[i].lhs != '\0') {
            printf("%c=%s\n", pr[i].lhs, pr[i].rhs);
        }
    }

    return 0;
}

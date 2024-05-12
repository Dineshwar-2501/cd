#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSingleLineComment(char *line) {
    // Check for single-line comment
    if (strstr(line, "//") == line) {
        return true;
    }
    return false;
}

bool isMultiLineComment(char *line) {
    // Check for multi-line comment start
    if (strstr(line, "/*") == line) {
        return true;
    }
    return false;
}

int main() {
    char line[100];
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);
    
    if (isSingleLineComment(line)) {
        printf("The input is a single-line comment.\n");
    } else if (isMultiLineComment(line)) {
        printf("The input is a multi-line comment.\n");
    } else {
        printf("The input is not a comment.\n");
    }
    
    return 0;
}

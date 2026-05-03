#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200
#define THRESHOLD 3

// Function to check if token is temporary variable like t1, t2, t10
int isTemporary(char token[]) {
    if (token[0] == 't') {
        int i = 1;
        if (isdigit(token[i])) {
            while (token[i] != '\0') {
                if (!isdigit(token[i]))
                    return 0;
                i++;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    int blocks, lines, i, j;
    char instruction[MAX_LENGTH];

    printf("Enter number of basic blocks: ");
    scanf("%d", &blocks);

    for (i = 1; i <= blocks; i++) {
        int tempCount = 0;

        printf("\nEnter number of instructions in Block %d: ", i);
        scanf("%d", &lines);

        getchar();  // Clear input buffer

        printf("Enter the three-address instructions:\n");

        for (j = 0; j < lines; j++) {
            fgets(instruction, sizeof(instruction), stdin);

            char *token = strtok(instruction, " =+-*/;\n");

            while (token != NULL) {
                if (isTemporary(token)) {
                    tempCount++;
                }
                token = strtok(NULL, " =+-*/;\n");
            }
        }

        printf("\nBlock %d Analysis:\n", i);
        printf("Temp_Variables_Per_Block = %d\n", tempCount);

        if (tempCount > THRESHOLD)
            printf("Is_Temp_Heavy = TRUE\n");
        else
            printf("Is_Temp_Heavy = FALSE\n");
    }

    return 0;
}

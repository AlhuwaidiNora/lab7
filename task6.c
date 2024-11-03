#include <stdio.h>
#include <string.h>

void filterLogFile(const char *code) {
    FILE *input = fopen("simulation.log", "r");
    FILE *output = fopen("filtered_log.txt", "w");
    char line[256];
    int count = 0;

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), input)) {
        if (strstr(line, code)) {
            fputs(line, output);
            count++;
        }
    }

    fclose(input);
    fclose(output);
    printf("Total occurrences of %s: %d\n", code, count);
}

int main() {
    char code[10];
    printf("Enter error/warning code to filter: ");
    scanf("%s", code);
    filterLogFile(code);
    return 0;
}


#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file = fopen("task2test.txt", "r");
    if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
    }

    char line[100];
    int lines = 0, words = 0, characters = 0;

    while (fgets(line, sizeof(line), file)) {
        lines++;
        for (int i = 0; line[i] != '\0'; i++) {
            characters++;
            if (isspace(line[i]) && !isspace(line[i + 1])) {
                words++;
            }
        }
    }

    fclose(file);
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, characters);

    return 0;
}


#include <stdio.h>
#include <string.h>

void encrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + 3) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + 3) % 26) + 'a';
        }
    }
}

void decrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - 3 + 26) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - 3 + 26) % 26) + 'a';
        }
    }
}

void fileEncrypt(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + 3) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + 3) % 26) + 'a';
        }
        fputc(ch, output);
    }
    fclose(input);
    fclose(output);
}

int main() {
    char choice, method, text[256];
    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &choice);
    printf("Do you want to process a (F)ile or enter a (S)tring? ");
    scanf(" %c", &method);

    if (method == 'S') {
        printf("Enter the string: ");
        scanf(" %[^\n]%*c", text);
        if (choice == 'E') {
            encrypt(text);
            printf("Encrypted string: %s\n", text);
        } else {
            decrypt(text);
            printf("Decrypted string: %s\n", text);
        }
    } else {
        char inputFile[50], outputFile[50];
        printf("Enter input filename: ");
        scanf("%s", inputFile);
        printf("Enter output filename: ");
        scanf("%s", outputFile);
        if (choice == 'E') {
            fileEncrypt(inputFile, outputFile);
            printf("File encrypted.\n");
        } else {
            printf("File decryption is not implemented in this example.\n");
        }
    }

    return 0;
}


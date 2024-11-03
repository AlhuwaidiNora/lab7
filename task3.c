#include <stdio.h>

void convertBitstreamToHex(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int bit;
    unsigned char byte = 0;
    int bitCount = 0;

    while (fscanf(input, "%d", &bit) == 1) {
        byte |= (bit << bitCount);
        bitCount++;

        if (bitCount == 8) {
            fprintf(output, "%02X\n", byte);
            byte = 0;  // Reset byte for the next 8 bits
            bitCount = 0;
        }
    }

    if (bitCount > 0) {
        fprintf(output, "%02X\n", byte);
    }

    fclose(input);
    fclose(output);
}

int main() {
    convertBitstreamToHex("bitstream.bit", "bitstream.hex");
    printf("Conversion completed. Check 'bitstream.hex' for output.\n");
    return 0;
}

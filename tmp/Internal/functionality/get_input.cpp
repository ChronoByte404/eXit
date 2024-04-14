#include <stdio.h>

int main() {
    char input_text[256];
    printf("\n\nYou: ");
    scanf("%255s", input_text); // Limit input to 255 characters to prevent buffer overflow

    FILE *file = fopen("./temp/memory/input.txt", "w+");
    if (file != NULL) {
        fprintf(file, "%s", input_text); // Write input_text to the file
        fclose(file);
        printf("Text saved to file.\n");
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}

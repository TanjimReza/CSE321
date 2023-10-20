#include <stdio.h>

int main() {
    int text_size = 100;
    char text[text_size];
    char output[text_size];
    
    printf("Enter text: ");
    fgets(text, text_size, stdin);


    int i = 0;
    int c = 0;
    int white_space_check = 0; // 0 = false, 1 = true

    while (text[i] != '\0') {
        // printf("%c \n", text[i]);
        if (text[i] == ' ') {
            // printf("Found whitespace at %d \n", i);
            if (white_space_check == 0) {
                output[c] = text[i];
                c++;
                white_space_check = 1;
            }
        }
        else {
            output[c] = text[i];
            white_space_check = 0;
            c++;
        }
        
        i++;
    }
    printf("Output: %s", output);

    return 0;
}
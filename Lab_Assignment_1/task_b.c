#include <stdio.h>

int main()
{
    int text_size = 100;
    char text[text_size];
    char output[text_size];

<<<<<<< HEAD
    // Take input from file
    FILE *file_pointer;
    file_pointer = fopen("task_b_input.txt", "r");
    fgets(text, text_size, file_pointer);
    printf("Input: %s", text);

    int i = 0;
    int c = 0;
    int white_space_check = 0; // 0 = false, 1 = true

    while (text[i] != '\0')
    {
        // printf("%c \n", text[i]);
        if (text[i] == ' ')
        {
            // printf("Found whitespace at %d \n", i);
            if (white_space_check == 0)
            {
                output[c] = text[i];
                white_space_check = 1;
                c++;
            }
        }
        else
        {
            output[c] = text[i];
            white_space_check = 0;
            c++;
        }

        i++;
    }
    printf("Output: %s", output);
    FILE *file_pointer2;
    file_pointer2 = fopen("task_b_output.txt", "w");
    fprintf(file_pointer2, "%s", output);
    fclose(file_pointer2);
    
=======
    printf("Enter text: ");
    fgets(text, text_size, stdin);
    char *tok = text;
    while (*tok != '\0')
    {
        if (*tok != ' ')
        {
            printf("%c", *tok);
            fprintf(output, "%c", *tok);
        }
        else
        {
            printf(" ");
            fprintf(output, " ");
            while (*(tok + 1) == ' ')
            {
                tok++;
            }
        }
        tok++;
    }

    fclose(output);
    return 0;
>>>>>>> 91fac4fa361f1ec8fa82f4237a26eea17b9612f9
    return 0;
}
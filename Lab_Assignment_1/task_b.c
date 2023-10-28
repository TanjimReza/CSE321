#include <stdio.h>

int main()
{
    int text_size = 100;
    char text[text_size];
    char output[text_size];

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
    return 0;
}
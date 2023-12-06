#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n_args = argc;
    char *exe_file = argv[0];
    char *text_file = argv[1];
    printf("n_args: %d\n", n_args);
    printf("exe%s\n", exe_file);
    printf("text: %s\n", text_file);

    int fp = open(text_file, O_WRONLY | O_CREAT, 0600);
    if (fp < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while (1)
    {
        char user_input[100];
        printf("Enter a string: ");
        fgets(user_input, 100, stdin);

        // printf("user_input: %s\n", user_input);

        if (strcmp(user_input, "-1\n") == 0)
        {
            exit(0);
        }

        int r = write(fp, user_input, strlen(user_input));
        if (r < 0)
        {
            printf("Error writing to #include <unistd.h>file\n");
            exit(1);
        }
    }
    return 0;
}
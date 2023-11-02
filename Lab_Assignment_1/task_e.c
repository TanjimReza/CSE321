#include <stdio.h>

int main()
{
    char palindromer[100];
    printf("Enter string: ");
    scanf("%s", palindromer);

    int length = 0;
    while (palindromer[length] != '\0')
    {
        length++;
    }
    // printf("Length: %d \n", length);

    // check palindrome using pointer

    char *start_pointer = palindromer;
    char *end_pointer = palindromer + length - 1;
    int palindrome = 1; // 1 = true, 0 = false

    while (*start_pointer != '\0')
    {
        if (*start_pointer != *end_pointer)
        {
            palindrome = 0;
            break;
        }
        start_pointer++;
        end_pointer--;
    }

    if (palindrome == 1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
}
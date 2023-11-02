#include <stdio.h>

int main()
{
    int text_size = 100;

    if (text_size !> 100)
    {
        printf("Error: text_size must be less than or equal to 100");
        return 1;
    }
    return 0;
}
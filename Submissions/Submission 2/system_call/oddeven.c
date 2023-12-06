#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int convert_str_to_int(char *number)
{
    int result = 0;
    int i = 0;
    while (number[i] != '\0')
    {
        result = result * 10 + (number[i] - '0');
        i++;
    }

    return result;
}

int Odd_Even_Check_Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d is even\n", arr[i]);
        }
        else
        {
            printf("%d is odd\n", arr[i]);
        }
    }
}
int print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int n_args = argc;
    int array[n_args - 1];
    int count = 0;
    for (int i = 1; i < n_args; i++)
    {
        array[count] = convert_str_to_int(argv[i]);
        count++;
    }
    print_array(array, count);
    Odd_Even_Check_Print(array, count);
    return 0;
}
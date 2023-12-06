#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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

int *Descending_Bubble_Sort(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (arr[j - 1] < arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main(int argc, char *argv[])
{
    // printf("Argc: %d\n", argc);
    // printf("Argv0: %s\n", argv[0]);
    // printf("Argv1: %s\n", argv[1]);
    // printf("Argv2: %s\n", argv[2]);

    // printf("Argv: ");

    int n_args = argc;
    int array[n_args - 1];
    int count = 0;
    for (int i = 1; i < n_args; i++)
    {
        array[count] = convert_str_to_int(argv[i]);
        count++;
    }

    printf("\n");
    int *sorted_array = Descending_Bubble_Sort(array, n_args - 1);
    print_array(sorted_array, count);

    
}
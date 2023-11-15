#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int print_array_from_pointer(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 7, 1, 6, 8};  // Declare arr as an array of integers
    int *ptr = arr;  // Assign arr to ptr
    // print ptr

    printf("ptr: %d\n", ptr);

    // print the array using a pointer 
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", *(ptr + i));
    // }

    print_array_from_pointer(ptr, 5);
}
#include <stdio.h>
#include <string.h>

int main()
{
    int arr_perfect_numbers[100];
    int position = 0;
    int start = 0;
    int end = 0;
    scanf("%d", &start);
    scanf("%d", &end);
    // printf("Start: %d, End: %d\n", start, end);

    for (int i = start; i <= end; i++)
    {
        // printf("i: %d\n", i);
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                // printf("j: %d\n", j);

                sum += j;
            }
        }
        if (sum == i)
        {
            arr_perfect_numbers[position] = i;
            position++;
        }
    }
    // printf("Output: ");
    for (int i = 0; i < position; i++)
    {
        printf("%d\n", arr_perfect_numbers[i]);
    }
}
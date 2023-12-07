#include <stdio.h>
#include <stdbool.h>

/////////////////////////////////

void print_matrix(int rows, int cols, int mat[rows][cols])
{
    // printf("%d, %d \n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        printf("[");
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("]\n");
    }
}

void subtract_matrix(int rows, int cols, int mat_a[rows][cols], int mat_b[rows][cols], int mat_res[rows][cols])
{
    // mat_res = mat_a - mat_b
    // done for all rows and all columns

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat_res[i][j] = mat_a[i][j] - mat_b[i][j];
        }
    }
}

bool is_less_than_or_equals(int length, int array_a[], int array_b[])
{
    // returns true  or 1 if (array_a <= array_b) is satisfied for all items
    // returns false or 0 if one item fails the (array_a <= array_b) test
    // write code

    for (int i = 0; i < length; i++)
    {
        if (array_a[i] > array_b[i])
        {
            return false;
        }
    }
    return true;
}

void add_array_values(int length, int array_a[], int array_b[], int array_res[])
{
    // array_res = array_a + array_b
    // done for all items

    // write code
    for (int i = 0; i < length; i++)
    {
        array_res[i] = array_a[i] + array_b[i];
    }
}

void generate_completion_state_matrix(int length, bool array[], bool value)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = value;
    }
}

void print_process_sequence(int length, int array[])
{
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            printf("P%d.\n", array[i]);
        }
        else
        {
            printf("P%d -> ", array[i]);
        }
    }
}

int main()
{

    int n = 6;                        // Number of processes
    int m = 4;                        // Number of resources
    int alloc[6][4] = {{0, 1, 0, 3},  // P0 // Allocation Matrix
                       {2, 0, 0, 3},  // P1
                       {3, 0, 2, 0},  // P2
                       {2, 1, 1, 5},  // P3
                       {0, 0, 2, 2},  // P4
                       {1, 2, 3, 1}}; // P5
    int max[6][4] = {{6, 4, 3, 4},    // P0 // MAX Matrix
                     {3, 2, 2, 4},    // P1
                     {9, 1, 2, 6},    // P2
                     {2, 2, 2, 8},    // P3
                     {4, 3, 3, 7},    // P4
                     {6, 2, 6, 5}};   // P5
    int avail[4] = {2, 2, 2, 1};      // Available resource

    int need[n][m]; // Need Matrix
    // use subtract_matrix() to calculate need matrix
    bool is_safe = true;
    int completed_processes = 0;
    // print_matrix(n, m, alloc);
    //! Need Matrix
    subtract_matrix(n, m, max, alloc, need);
    //! Process Completion State

    bool completed[n];
    generate_completion_state_matrix(n, completed, false);
    int completed_process_sequence[n];
    int completed_process_sequence_index = 0;
    while (completed_processes < n)
    {
        bool ran_at_least_one = false;

        for (int process = 0; process < n; process++)
        {
            if (completed[process] == false)
            {
                //! need = need[process];
                //! alloc = alloc[process];

                if (is_less_than_or_equals(m, need[process], avail))
                {
                    // printf(" %d completed\n", process);
                    completed_process_sequence[completed_process_sequence_index] = process;
                    completed_process_sequence_index++;
                    completed[process] = true;
                    ran_at_least_one = true;
                    completed_processes++;
                    add_array_values(m, avail, alloc[process], avail);
                }
            }
        }
        if (ran_at_least_one == false)
        {
            is_safe = false;
            break;
        }
    }

    if (is_safe)
    {
        printf("Safe Here\n");
        printf("Safe Sequence: ");
        print_process_sequence(n, completed_process_sequence);
    }
    else
    {
        printf("Deadlock Ahead\n");
    }
}

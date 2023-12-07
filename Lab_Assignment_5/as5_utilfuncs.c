#include <stdio.h>
#include <stdbool.h>

/////////////////////////////////

void print_matrix(int rows, int cols, int mat[][cols])
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

void subtract_matrix(int rows, int cols, int mat_a[][cols], int mat_b[][cols], int mat_res[][cols])
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
}

/////////////////////////////////

int main()
{
    int n = 5;                        // Number of processes
    int m = 4;                        // Number of resources
    int alloc[5][4] = {{0, 1, 0, 3},  // P0 // Allocation Matrix
                       {2, 0, 0, 0},  // P1
                       {3, 0, 2, 0},  // P2
                       {2, 1, 1, 5},  // P3
                       {0, 0, 2, 2}}; // P4
    int max[5][4] = {{6, 4, 3, 4},    // P0 // MAX Matrix
                     {3, 2, 2, 1},    // P1
                     {9, 1, 2, 6},    // P2
                     {2, 2, 2, 8},    // P3
                     {4, 3, 3, 7}};   // P4
    int avail[4] = {3, 3, 2, 1};

    // print_matrix(n, m, need);
    // printf("%d\n", is_less_than_or_equals(m, avail, need[4]));

    // #Consider max_matrix, alloc_matrix, and available_resources are given
    // declare is_safe as True

    // alloc_matrix # do for each row's each column
    // need_matrix = max_matrix -
    int need[n][m]; // Need Matrix
    // use subtract_matrix() to calculate need matrix
    bool is_safe = true;
    int completed_processes = 0;
    // print_matrix(n, m, alloc);
    //! Need Matrix
    subtract_matrix(n, m, max, alloc, need);
    //! Process Completion State
    bool completed[n];
    for (int i = 0; i < n; i++)
    {
        completed[i] = false;
    }
    // while not all processes are finished:
    //     declare ran_at_least_one as False

    //     for proc in processes:
    //         if proc is not completed:
    //             need_row = the row from need_matrix for proc
    //             allocated_row = the row from alloc_matrix for proc

    //             if need_row available_resources is satisfied: # check for each column
    //                 set proc completed to True
    //                 set ran-at-least-one to True
    //                 increment the count of completed processes
    //                 available_resources += allocated_row # do for each column

    //     if ran_at_least_one is False:
    //         set is_safe to False
    //         break the while loop

    while (completed_processes < n)
    {
        bool ran_at_least_one = false;

        for (int process = 0; process < n; process++)
        {
            if (completed[process] == false)
            {
                // get need row from need matrix
                need[process];
                // get allocated row from alloc matrix
                alloc[process];

                if (is_less_than_or_equals(m, avail, need[process]))
                {
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
        printf("Safe State\n");
    }
    else
    {
        printf("Unsafe State\n");
    }
    
}
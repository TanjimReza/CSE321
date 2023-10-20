#include <stdio.h>

int main() {
    int my_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    int reversed_array[10] = {};

    for (int i = 0; i < 10; i++) {
        reversed_array[i] = my_array[9 - i];
    }

    // ok
    for (int i = 0; i < 10; i++) {
        printf("%d ", reversed_array[i]);
    }
    return 0;
}   
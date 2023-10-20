#include <stdio.h>

// take a string with spaces and numbers and characters and show the sum of the numbers
int main() {
    char str[100];
    int sum = 0;
    printf("Enter a string with numbers: ");
    scanf("%[^\n]", str);
    fgets
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // printf("Found number: %c\n", str[i]);
            sum += str[i] - '0';
        }
    }
    printf("Sum = %d\n", sum);
    return 0;
}
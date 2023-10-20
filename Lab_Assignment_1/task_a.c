#include <stdio.h>

float add(float first_number, float second_number) {
    return first_number + second_number;
}

float subtract(float first_number, float second_number) {
    return first_number - second_number;
}

float multiply(float first_number, float second_number) {
    return first_number * second_number;
}

int main() {
    float first_number = 0; 
    float second_number = 0;
    char operator[] = "";

    printf("Enter first, second number and operator:");
    scanf("%f %f %s", &first_number, &second_number, operator);
    // printf("%f %f %s", first_number, second_number, operator);
    add(first_number, second_number);

    if (first_number > second_number) {
        printf("Result: %.2f", subtract(first_number, second_number));   
    }

    else if (first_number < second_number) {
        printf("Result: %.2f", add(first_number, second_number));   
    }

    else if  (first_number == second_number) {
        printf("Result: %.2f", multiply(first_number, second_number));
    }
    
    return 0;
}


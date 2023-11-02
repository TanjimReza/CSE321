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
    float result = 0;
    float first_number = 0; 
    float second_number = 0;
    char operator[] = "";

    printf("Enter first, second number and operator:");
    scanf("%f %f %s", &first_number, &second_number, operator);
    

    if (first_number > second_number) {
        result = subtract(first_number, second_number);
        printf("Result: %.2f", result);   
    }

    else if (first_number < second_number) {
        result = add(first_number, second_number);
        printf("Result: %.2f", result);
    }

    else if  (first_number == second_number) {
        result = multiply(first_number, second_number);
        printf("Result: %.2f", result);
    }
    
    return 0;
}


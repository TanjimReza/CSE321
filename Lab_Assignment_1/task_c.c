#include <stdio.h>


int main() {

    int lower_case = 0;
    char lower_case_msg[] = "Lowercase missing";
    
    int upper_case = 0;
    char upper_case_msg[] = "Uppercase missing";

    int digits = 0;
    char digit_msg[] = "Digit missing";

    int special_characters = 0;
    char special_characters_msg[] = "Special character missing";
    
    char output[] = "";

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            lower_case = 1;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            upper_case = 1;
        } else if (input[i] >= '0' && input[i] <= '9') {
            digits = 1;
        } else {
            special_characters = 1;
        }
    }

    int previous_message = 0;

    if (lower_case == 0) {
        printf("%s", lower_case_msg);
        previous_message = 1;

    }
    if (upper_case == 0) {
        if (previous_message == 1) {
            printf(", ");
        }
        printf("%s", upper_case_msg);
        previous_message = 1;
    }
    if (digits == 0) {
        if (previous_message == 1) {
            printf(", ");
        }
        printf("%s", digit_msg);
        previous_message = 1;
    }
    if (special_characters == 0) {
        if (previous_message == 1) {
            printf(", ");
        }
        printf("%s", special_characters_msg);
        previous_message = 1;
    }

    if (lower_case == 1 && upper_case == 1 && digits == 1 && special_characters == 1) {
        printf("OK");
    }

    return 0;
}
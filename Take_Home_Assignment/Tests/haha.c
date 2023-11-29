#include <stdio.h>
int main(){
    printf("Hello World\n");

    for (int i=1; i < 12; i+=2){
        printf("i: %d\n", i);
        printf("i+1: %d\n", i+1);
    }

    return 0;
}
//
// Created by Kahaan Shah on 25/09/22.
//

#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = 5;
    int* y = &x;
    printf("Value: %d \n", x);
    printf("Value again: %d \n", *y);
    printf("Address: %p \n", y);

    int* ptr = malloc(1*sizeof(int));
    *ptr = 10;
    printf("Value: %d \n", *ptr);
    printf("Address: %p \n", ptr);
    free(ptr);

    int *ptr_arr = malloc(3*sizeof(int));
    ptr_arr[0] = 15;
    printf("Value: %d \n", ptr_arr[0]);
    free(ptr_arr);

    return 0;
}
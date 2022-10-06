#include <stdio.h>
#include <stdlib.h>

//Create an array of given length with random numbers
int* createRandomArray(int size) {
    if (size<1) {return NULL;}
    
    int* arr = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%1000;
    }

    return arr;
}

//Print array
void printArray(int* arr, int size) {
    if (size>0) {printf("Array: %d",arr[0]);}
    for (int i = 1; i < size; i++) {
        printf(", %d", arr[i]);
    }
    printf(". \n");
    
}

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int* arr, int size) {
    for (int done = 0; done < size; done++) {
        for (int i = 0; i<size-done-1; i++) {
            if (arr[i]>arr[i+1]) {swap(&arr[i], &arr[i+1]);}
        }
    }
}

int findMaxIndex(int* arr, int upto) {
    int maxval = arr[0];
    int maxind = 0;
    for (int i=1; i<upto+1; i++) {
        if (arr[i]>maxval) {maxind = i;}
    }

    return maxind;
}

void selectionSort(int* arr, int size) {
    int maxind;
    for (int i = size-1; i > 0; i--) {
        maxind = findMaxIndex(arr, i);
        swap(&arr[maxind], &arr[i]);
    }
}


int main(int argc, char** argv) {

    int* myarr = createRandomArray(7);
    printArray(myarr, 7);
    selectionSort(myarr, 7);
    printArray(myarr, 7);

    return 0;
}
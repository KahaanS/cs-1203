#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Create an array of given length with random numbers
int* createRandomArray(int size) {
    if (size<1) {return NULL;}
    
    int* arr = malloc(size*sizeof(int));
    srand(time(NULL));
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

//Swap 2 elements in an array
void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//Code for bubble sort
void bubbleSort(int* arr, int size) {
    for (int done = 0; done < size; done++) {
        for (int i = 0; i<size-done-1; i++) {
            if (arr[i]>arr[i+1]) {swap(&arr[i], &arr[i+1]);}
        }
    }
}

//Find the index of the maximum element in an array upto a certain element
int findMaxIndex(int* arr, int upto) {
    int maxval = arr[0];
    int maxind = 0;
    for (int i=1; i<upto+1; i++) {
        if (arr[i]>maxval) {maxind = i;}
    }

    return maxind;
}

//Code for selection sort
void selectionSort(int* arr, int size) {
    int maxind;
    for (int i = size-1; i > 0; i--) {
        maxind = findMaxIndex(arr, i);
        swap(&arr[maxind], &arr[i]);
    }
}


//Code for parition
int partition(int* arr, int lowIndex, int highIndex) {
    srand(time(NULL));
    int randIndex = rand()%(highIndex + 1 - lowIndex) + lowIndex;
    swap(&arr[randIndex], &arr[highIndex]);

    int pivot = arr[highIndex];
    int greaterIndex = lowIndex-1;

    for (int curr = lowIndex; curr<highIndex; curr++) {
        if (arr[curr]<=pivot) {
            greaterIndex++;
            swap(&arr[greaterIndex], &arr[curr]);
        }
    }

    swap(&arr[greaterIndex+1], &arr[highIndex]);
    return greaterIndex+1;
}

//Code for quick sort
void quickSort(int* arr, int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int partIndex = partition(arr, lowIndex, highIndex);
        quickSort(arr, partIndex+1, highIndex);
        quickSort(arr, lowIndex, partIndex-1);
    }
}


int main(int argc, char** argv) {

    int* myarr = createRandomArray(7);
    printArray(myarr, 7);
    quickSort(myarr, 0, 6);
    printArray(myarr, 7);

    return 0;
}
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

//Heapify
void heapify(int* arr, int len, int rootIndex) {
    int minIndex = rootIndex;
    int leftIndex = rootIndex*2+1;
    int rightIndex = rootIndex*2+2;

    if (leftIndex<len && arr[leftIndex]<arr[minIndex]) {
        minIndex = leftIndex;
    }

    if (rightIndex<len && arr[rightIndex]<arr[minIndex]) {
        minIndex = rightIndex;
    }

    if (minIndex != rootIndex) {
        swap(&arr[rootIndex], &arr[minIndex]);
        heapify(arr, len, minIndex);
    }
}

void buildHeap(int* arr, int len) {
    int lastLeafIndex = (len/2)-1;
    for (int i = lastLeafIndex; i>=0; i--) {
        heapify(arr, len, i);
    }
}

int extract_min(int* arr, int* len) {
    swap(&arr[0], &arr[*len-1]);
    int min = arr[*len-1];
    heapify(arr, *len-1, 0);
    *len = *len-1;
    return min;
}

int* insert(int* arr, int* len, int num) {
    int* newarr = realloc(arr, sizeof(int)*(*len+1));
    newarr[*len] = num;
    buildHeap(newarr, *len+1);
    *len=*len+1;
    return newarr;
}

void heapSort(int* heap, int len) {
    while(len>0) {
        extract_min(heap, &len);
    }
}

int main(int argc, char** argv) {

    int len=10;

    int* myarr = createRandomArray(len);
    printArray(myarr, len);
    buildHeap(myarr, len);
    printArray(myarr, len);
    int min = extract_min(myarr, &len);
    min++;
    printArray(myarr, len);
    min = extract_min(myarr, &len);
    min++;
    printArray(myarr, len);
    myarr = insert(myarr, &len, 200);
    printArray(myarr, len);
    heapSort(myarr, len);
    printArray(myarr, len);
    
    return 0;
}

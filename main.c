#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SORT_IMPL
#include "sort.h"

typedef void (*sortFunc)(int*, int);
#define ARRAY_CAPACITY 5

void generateRandomArray(int array[], int length) {
    srand(time(NULL));
    for(int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
}

void printArr(int array[], int begin, int end) {
    printf("[");
    for (int i = begin; i <= end; i++) {
        if (i > begin){
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

double sortGetTime(int array[], int length, sortFunc f) {
    clock_t start_time = clock();
    (*f)(array,length);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time); // CLOCKS_PER_SEC;
    return elapsed_time;
}

int main(void) {
    int numbers[ARRAY_CAPACITY] = {0};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    generateRandomArray(numbers, length);
    double time = sortGetTime(numbers, length, quickSort);

    printf("Time to quick sort %d elements is %lf.\n", ARRAY_CAPACITY, time);

    generateRandomArray(numbers, length);
    time = sortGetTime(numbers, length, bubbleSort);
    printf("Time to quick sort %d elements is %lf.\n", ARRAY_CAPACITY, time);
    return 0;
}

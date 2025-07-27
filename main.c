#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SORT_IMPL
#include "sort.h"

typedef void (*SortFunc)(int*, int);
#define ARRAY_CAPACITY 10000

void generate_random_array(int array[], int length) {
    srand(time(NULL));
    for(int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
}

void print_array(int array[], int begin, int end) {
    printf("[");
    for (int i = begin; i <= end; i++) {
        if (i > begin){
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

double sort_get_time(int array[], int length, SortFunc f) {
    clock_t start_time = clock();
    (*f)(array,length);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main(void) {
    int numbers[ARRAY_CAPACITY] = {0};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    generate_random_array(numbers, length);
    double time = sort_get_time(numbers, length, quick_sort);

    printf("Time to quick sort %d elements is %lf.\n", ARRAY_CAPACITY, time);

    generate_random_array(numbers, length);
    time = sort_get_time(numbers, length, bubble_sort);
    printf("Time to bubble sort %d elements is %lf.\n", ARRAY_CAPACITY, time);
    return 0;
}

/*
 * File: performance.c
 *
 * Sort a shuffled array (of SIZE integers elements) using each sorting algorithm provided by libsort.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>

#include "bubblesort.h"
#include "combsort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selectionsort.h"
#include "shellsort.h"
#include "sort.h"

#define SIZE 4096

// Print an array
void print(int* array);
// Swap 2 elements in the array
void swap_integers(int* array, int i1, int i2);
// Shuffle the array
void shuffle(int* array);
// Compare integers
int intcmp(const void* i1, const void* i2);
// Shuffle the array, sort it and returns the execution time (in milliseconds)
double shuffle_and_sort(int* array, void(*sort)(void*, size_t, size_t, int(*compare)(const void*, const void*)));

int main(void) {
  int i;
  int array[SIZE];
  // Init array
  for (i = 0; i < SIZE; i++)
    array[i] = i + 1;
  printf("Size of the array : %d\n", SIZE);
  printf("Bubble sort : %f ms\n", shuffle_and_sort(array, bubblesort));
  printf("Comb sort : %f ms\n", shuffle_and_sort(array, combsort));
  printf("Heapsort : %f ms\n", shuffle_and_sort(array, heapsort));
  printf("Insertion sort : %f ms\n", shuffle_and_sort(array, insertionsort));
  printf("Merge sort : %f ms\n", shuffle_and_sort(array, mergesort));
  printf("Quicksort : %f ms\n", shuffle_and_sort(array, quicksort));
  printf("Selection sort : %f ms\n", shuffle_and_sort(array, selectionsort));
  printf("Shell sort : %f ms\n", shuffle_and_sort(array, shellsort));
  return 0;
}

void print(int* array) {
  int i;
  for (i = 0; i < SIZE; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void swap_integers(int* array, int i1, int i2) {
  int tmp = array[i1];
  array[i1] = array[i2];
  array[i2] = tmp;
}

void shuffle(int* array) {
  int i, index1, index2;
  srand(time(NULL));
  for (i = 0; i < SIZE * 2; i++) { // (SIZE * 2) permutations
    index1 = rand() % SIZE;
    index2 = rand() % SIZE;
    swap_integers(array, index1, index2);
  }
}

int intcmp(const void* i1, const void* i2) {
  return (*(int*) i1) - (*(int*) i2);
}

double shuffle_and_sort(int* array, void(*sort)(void*, size_t, size_t, int(*compare)(const void*, const void*))) {
  struct timespec start, end;
  shuffle(array);
  //print(array);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  sort(array, SIZE, sizeof(int), intcmp);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
  //print(array);
  return (double)(end.tv_nsec - start.tv_nsec) / 1000000; // Convert nanoseconds to milliseconds
}

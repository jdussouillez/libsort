#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort.h"
#include "../include/quicksort.h"

/*
 * Partition the portion of the array between indexes "begin" and "end".
 */
static int partition(void* base, int begin, int end, size_t size, int pivot, int(*compare)(const void*, const void*)) {
  int i, index = begin;
  void* pivot_value = malloc(size);
  memcpy(pivot_value, base + (pivot * size), size);
  swap(base + (pivot * size), base + (end * size), size);
  for (i = begin; i < end; i++) {
    if (compare(base + (i * size), pivot_value) < 0) {
      swap(base + (i * size), base + (index * size), size);
      index++;
    }
  }
  swap(base + (index * size), base + (end * size), size);
  free(pivot_value);
  return index;
}

/*
 * Sort the array between indexes "begin" and "end" (recursive).
 */
static void quicksort_rec(void* base, int begin, int end, size_t size, int(*compare)(const void*, const void*)) {
  int pivot, pivotIndex;
  if (begin < end) {
    pivotIndex = (begin + end) / 2;
    pivot = partition(base, begin, end, size, pivotIndex, compare);
    quicksort_rec(base, begin, pivot - 1, size, compare);
    quicksort_rec(base, pivot + 1, end, size, compare);
  }
}

void quicksort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  quicksort_rec(base, 0, nmemb - 1, size, compare);
}

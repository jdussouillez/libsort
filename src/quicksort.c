#include <stdio.h>

#include "../include/sort.h"
#include "../include/quicksort.h"

/*
 * Partition the portion of the array between indexes "begin" and "end".
 */
static int partition(void* base, int begin, int end, size_t size, int pivot, int(*compare)(const void*, const void*)) {
  int i, j;
  swap(base + (pivot * size), base + (end * size), size);
  j = begin;
  for (i = begin; i < end; i++) {
    if (compare(base + (i * size), base + (end * size)) <= 0) {
      swap(base + (i * size), base + (j * size), size);
      j++;
    }
  }
  swap(base + (end * size), base + (j * size), size);
  return j;
}

/*
 * Sort the array between indexes "begin" and "end" (recursive).
 */
static void quicksort_rec(void* base, int begin, int end, size_t size, int(*compare)(const void*, const void*)) {
  int pivot;
  if (begin < end) {
    pivot = partition(base, begin, end, size, begin, compare); // begin as pivot
    quicksort_rec(base, begin, pivot - 1, size, compare);
    quicksort_rec(base, pivot + 1, end, size, compare);
  }
}

void quicksort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  quicksort_rec(base, 0, nmemb - 1, size, compare);
}

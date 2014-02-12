#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort.h"
#include "../include/mergesort.h"

/*
 * Sort (merge) a part of the array
 */
void merge(void* base, void* helper, int left, int mid, int right, size_t size, int(*compare)(const void*, const void*)) {
  int i, j, k;
  // Copy the array
  for (i = left; i <= right; i++) {
    memcpy(helper + (i * size), base + (i * size), size); // helper[i] = base[i]
  }
  i = left;
  j = mid + 1;
  k = left;
  // Copy the smallest values back to the original array
  while (i <= mid && j <= right) {
    if (compare(helper + (i * size), helper + (j * size)) <= 0) {
      memcpy(base + (k * size), helper + (i * size), size);
      i++;
    }
    else {
      memcpy(base + (k * size), helper + (j * size), size);
      j++;
    }
    k++;
  }
  // Copy the rest of the left side of the array
  while (i <= mid) {
    memcpy(base + (k * size), helper + (i * size), size);
    k++;
    i++;
  }
}

/*
 * Sort the left and right side of the array, then combine them both (recursive)
 */
void mergesort_rec(void* base, void* helper, int left, int right, size_t size, int(*compare)(const void*, const void*)) {
  int mid;
  if (right > left) {
    mid = (right + left) / 2;
    mergesort_rec(base, helper, left, mid, size, compare);
    mergesort_rec(base, helper, (mid + 1), right, size, compare);
    merge(base, helper, left, mid, right, size, compare);
  }
}

void mergesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  void* helper = malloc(nmemb * size);
  mergesort_rec(base, helper, 0, nmemb - 1, size, compare);
  free(helper);
}

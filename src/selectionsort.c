#include <stdio.h>

#include "../include/sort.h"
#include "../include/selectionsort.h"

void selectionsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  int i, j, min;
  for (i = 0; i < nmemb - 1; i++) {
    min = i;
    for (j = i + 1; j < nmemb; j++) {
      if (compare(base + (j * size), base + (min * size)) < 0) // if base[i] < base[min]
	min = j;
    }
    if (min != i)
      swap(base + (i * size), base + (min * size), size);
  }
}

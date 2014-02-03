#include <stdio.h>

#include "../include/sort.h"
#include "../include/combsort.h"

int newgap(int gap) {
  gap = (gap * 10) / 13; // gap shrink factor = 1.3
  if (gap < 1)
    return 1;
  return (gap == 9 || gap == 10) ? 11 : gap;
}

void combsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  int gap = nmemb, swapped, i;
  do {
    swapped = 0;
    gap = newgap(gap);
    for (i = 0; i < (nmemb - gap); i++) {
      if (compare(base + (i * size), base + ((i + gap) * size)) > 0) {
	swapped = 1;
	swap(base + (i * size), base + ((i + gap) * size), size);
      }
    }
  } while (gap > 1 || swapped);
}

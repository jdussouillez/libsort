#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort.h"
#include "../include/shellsort.h"

void shellsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  int i, j, gap;
  void* tmp = malloc(size);
  for (gap = nmemb / 2; gap > 0; gap /= 2) {
    for (i = gap; i < nmemb; i++) {
      memcpy(tmp, base + (i * size), size);
      j = i;
      while (j >= gap && compare(tmp, base + ((j - gap) * size)) < 0) {
        memmove(base + (j * size), base + ((j - gap) * size), size);
	j -= gap;
      }
      memmove(base + (j * size), tmp, size);
    }
  }
  free(tmp);
}

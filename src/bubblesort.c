#include <stdio.h>

#include "../include/sort.h"
#include "../include/bubblesort.h"

void bubblesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return ;
  int i, j;
  void *m1, *m2;
  for (i = 0; i < nmemb; i++) {
    for (j = 1; j < nmemb - i; j++) {
      m1 = base + ((j - 1) * size);
      m2 = base + (j * size);
      if (compare(m1, m2) > 0)
	swap(m1, m2, size);
    }
  }
}

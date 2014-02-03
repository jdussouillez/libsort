#include <stdlib.h>
#include <string.h>

#include "../include/sort.h"

void swap(void* p1, void* p2, size_t size) {
  if (p1 == NULL || p2 == NULL)
    return;
  void* tmp = malloc(size);
  memmove(tmp, p1, size);
  memmove(p1, p2, size);
  memmove(p2, tmp, size);
  free(tmp);
}

int issorted(void* array, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (array == NULL || compare == NULL)
    return -1;
  int i;
  for (i = 0; i < nmemb - 1; i++) {
    if (compare(array + (i * size), array + ((i + 1) * size)) > 0)
      return 0;
  }
  return 1;
}

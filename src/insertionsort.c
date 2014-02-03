#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort.h"
#include "../include/insertionsort.h"

void insertionsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  int i, j;
  void* value = malloc(size);
  for (i = 1; i < nmemb; i++) {
    memcpy(value, base + (i * size), size); // value = base[i]
    for (j = i - 1; j >= 0 && compare(base + (j * size), value) > 0; j--) {
      memcpy(base + ((j + 1) * size), base + (j * size), size); // base[j + 1] = base[j]
    }
    memcpy(base + ((j + 1) * size), value, size); // base[j + 1] = value
  }
  free(value);
}

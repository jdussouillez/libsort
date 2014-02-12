#include <stdio.h>

#include "../include/sort.h"
#include "../include/heapsort.h"

/*
 * Heap sifting
 */
static void siftdown(void* base, size_t size, int(*compare)(const void*, const void*), int start, int end) {
  int root = start, child;
  void *proot, *pchild;
  while (((root * 2) + 1) <= end) {
    child = (root * 2) + 1;
    if (child + 1 <= end && compare(base + (child * size), base + ((child + 1) * size)) < 0) {
      child++;
    }
    proot = base + (root * size);
    pchild = base + (child * size);
    if (compare(proot, pchild) < 0) {
      swap(proot, pchild, size);
      root = child;
    }
    else
      return;
  }
}

/*
 * Puts elements of "base" in heap order
 */
static void heapify(void* base, size_t size, int(*compare)(const void*, const void*), int count) {
  int start = (count - 2) / 2; // binary heap
  while (start >= 0) {
    siftdown(base, size, compare, start, count - 1);
    start--;
  }
}

void heapsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*)) {
  if (base == NULL || compare == NULL)
    return;
  int end = nmemb - 1;
  heapify(base, size, compare, nmemb);
  while (end > 0) {
    // swap the root (max value) and the last element of the heap
    swap(base + (end * size), base, size);
    siftdown(base, size, compare, 0, --end);
  }
}

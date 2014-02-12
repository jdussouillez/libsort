#ifndef HEAPSORT_H
#define HEAPSORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Heap siftting
 */
void siftdown(void* base, size_t size, int(*compare)(const void*, const void*), int start, int end);

/*
 * Puts elements of "base" in heap order
 */
void heapify(void* base, size_t size, int(*compare)(const void*, const void*), int count);

/*
 * Sorts an array with "nmemb" elements of size "size" using the heapsort algorithm.
 * The "base" argument points to the start of the array.
 * The contents of the array are sorted in ascending order according to a comparison function pointed to
 * by "compare" which is called with two arguments that point to the objets being compared.
 *
 * The function returns no value (nothing is done if "base" or "compare" are NULL).
 *
 * See qsort(3) manpage for more informations.
 * Sorting algorithm information: http://en.wikipedia.org/wiki/Heapsort
 */
void heapsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // HEAPSORT_H

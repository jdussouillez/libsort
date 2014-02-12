#ifndef MERGESORT_H
#define MERGESORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Sort a part of the array
 */
void merge(void* base, void* helper, int left, int mid, int right, size_t size, int(*compare)(const void*, const void*));

/*
 * Sort the left and right side of the array, then combine them both (recursive)
 */
void mergesort_rec(void* base, void* helper, int left, int right, size_t size, int(*compare)(const void*, const void*));

/*
 * Sorts an array with "nmemb" elements of size "size" using the merge bubble sort algorithm.
 * The "base" argument points to the start of the array.
 * The contents of the array are sorted in ascending order according to a comparison function pointed to
 * by "compare" which is called with two arguments that point to the objets being compared.
 *
 * The function returns no value (nothing is done if "base" or "compare" are NULL).
 *
 * See qsort(3) manpage for more informations.
 * Sorting algorithm information: http://en.wikipedia.org/wiki/Merge_sort
 */
void mergesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // MERGESORT_H

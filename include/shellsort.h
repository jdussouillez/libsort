#ifndef SHELLSORT_H
#define SHELLSORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Sorts an array with "nmemb" elements of size "size" using the shell sort algorithm.
 * The "base" argument points to the start of the array.
 * The contents of the array are sorted in ascending order according to a comparison function pointed to
 * by "compare" which is called with two arguments that point to the objets being compared.
 *
 * The function returns no value (nothing is done if "base" or "compare" are NULL).
 *
 * See qsort(3) manpage for more informations.
 * Sorting algorithm information: http://en.wikipedia.org/wiki/Shellsort
 */
void shellsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // SHELLSORT_H

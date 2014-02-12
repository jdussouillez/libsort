#ifndef COMBSORT_H
#define COMBSORT_H

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Calculates and returns the new gap using the old one.
 */
int newgap(int gap);

/*
 * Sorts an array with "nmemb" elements of size "size" using the comb sort algorithm.
 * The "base" argument points to the start of the array.
 * The contents of the array are sorted in ascending order according to a comparison function pointed to
 * by "compare" which is called with two arguments that point to the objets being compared.
 *
 * The function returns no value (nothing is done if "base" or "compare" are NULL).
 *
 * See qsort(3) manpage for more informations.
 * Sorting algorithm information: http://en.wikipedia.org/wiki/Comb_sort
 */
void combsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // COMBSORT_H

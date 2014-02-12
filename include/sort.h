#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Swap p1 and p2 elements of size "size".
 */
void swap(void* p1, void* p2, size_t size);

/*
 * Returns 1 if the array pointed by p ("nmemb" elements of size "size")
 * is sorted (using "compare" function).
 */
int issorted(void* p, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // SORT_H

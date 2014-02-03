#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#ifdef __cplusplus
extern "C" {
#endif

void insertionsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // INSERTIONSORT_H

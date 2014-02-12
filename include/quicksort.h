#ifndef QUICKSORT_H
#define QUICKSORT_H

#ifdef __cplusplus
extern "C" {
#endif

int partition(void* base, int begin, int end, size_t size, int pivot, int(*compare)(const void*, const void*));

void quicksort_rec(void* base, int begin, int end, size_t size, int(*compare)(const void*, const void*));

void quicksort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // QUICKSORT_H

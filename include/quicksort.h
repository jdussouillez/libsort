#ifndef QUICKSORT_H
#define QUICKSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void quicksort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // QUICKSORT_H

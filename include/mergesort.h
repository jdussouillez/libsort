#ifndef MERGESORT_H
#define MERGESORT_H

#ifdef __cplusplus
extern "C" {
#endif

void mergesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // MERGESORT_H

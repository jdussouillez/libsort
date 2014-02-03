#ifndef RADIXSORT_H
#define RADIXSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void radixsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // RADIXSORT_H

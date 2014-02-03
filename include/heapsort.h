#ifndef HEAPSORT_H
#define HEAPSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void siftdown(void* base, size_t size, int(*compare)(const void*, const void*), int start, int end);

void heapify(void* base, size_t, int(*compare)(const void*, const void*), int count);

void heapsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // HEAPSORT_H

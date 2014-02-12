#ifndef MERGESORT_H
#define MERGESORT_H

#ifdef __cplusplus
extern "C" {
#endif

  void merge(void* base, void* helper, int left, int mid, int right, size_t size, int(*compare)(const void*, const void*));

  void mergesort_rec(void* base, void* helper, int left, int right, size_t size, int(*compare)(const void*, const void*));

void mergesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // MERGESORT_H

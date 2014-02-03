#ifndef HEAPSORT_H
#define HEAPSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void heapsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // HEAPSORT_H

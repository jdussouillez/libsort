#ifndef SHELLSORT_H
#define SHELLSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void shellsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // SHELLSORT_H

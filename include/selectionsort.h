#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void selectionsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // SELECTIONSORT_H

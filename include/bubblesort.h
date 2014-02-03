#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#ifdef __cplusplus
extern "C" {
#endif

void bubblesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // BUBBLESORT_H

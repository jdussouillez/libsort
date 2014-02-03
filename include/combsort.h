#ifndef COMBSORT_H
#define COMBSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void combsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // COMBSORT_H

#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

void swap(void* p1, void* p2, size_t size);

int issorted(void* p, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // SORT_H

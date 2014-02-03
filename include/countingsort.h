#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void countingsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // COUNTINGSORT_H

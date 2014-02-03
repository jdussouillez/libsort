#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#ifdef __cplusplus
extern "C" {
#endif

void bucketsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif // BUCKETSORT_H

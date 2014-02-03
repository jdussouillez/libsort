#ifndef BUCKETSORT_H
#define BUCKETSORT_H

void bucketsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

#endif // BUCKETSORT_H

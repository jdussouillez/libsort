libsort
=======

libsort is a static C library which implements the most popular sorting algorithms.
The functions can be used on "generic" arrays (primitive data types, structures...).

How to build
------------

Use the makefile to build the lib (bin/libsort.a):
``` bash
make # Build the lib and run the unit tests program.
make clean # Clean the temporary and objects file.
```

If you want to remove the lib and all the temporary files:
``` bash
make distclean
```

How to use
----------

The functions provided by the lib have the same prototypes (based on the qsort() function from stdlib.h) : 

``` C
void name_of_algorithm(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));
// void bubblesort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));
// void combsort(void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));
// ...
```
- The "base" argument points to the start of the array.
- The "nmemb" argument is the number of elemenst of the array.
- The "size" argument is the size of the elements of the array.
- The "compare" argment points to a function used to compare 2 elements of the array.

See the qort(3) manpage for more information.

Sorting algorithms
------------------

The sorting algorithms implemented are : 

- Bubble sort
- Comb sort
- Heapsort
- Insertion sort
- Merge sort
- Quicksort
- Selection sort
- Shell sort

The bucket and counting sorts are not implemented because they can only be used on arrays of integer.
See the [Wikipedia article about sorting algorithms](http://en.wikipedia.org/wiki/Sorting_algorithm#Popular_sorting_algorithms) for more informations.


Tools
-----

- Written with Emacs 24
- Built with gcc 4.8
- The testing program uses CUnit 2.1 (basic interface)
- Tested on GNU/Linux (Linux Mint 16)

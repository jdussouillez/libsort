libsort
=======

libsort is a static C library which implements the most popular sorting algorithms.
The functions can be used on "generic" arrays (primitive data types, structures...).

How to build
------------

Use the makefile to build the lib (bin/libsort.a):
``` bash
make # Build the lib and run the unit tests program.
make clean # Clean the temporary and objets file.
```

If you want to remove the lib and all the temporary files:
``` bash
make distclean
```

How to use
----------

// TODO

Sorting algorithms
------------------

The sorting algorithms implemented are : 

Bubble sort
Bucket sort
Comb sort
Counting sort
Heapsort
Insertion sort
Merge sort
Quicksort
Radix sort
Selection sort
Shell sort

See the [Wikipedia article about sorting algorithms](http://en.wikipedia.org/wiki/Sorting_algorithm#Popular_sorting_algorithms) for more informations.


Tools
-----

- Written with Emacs 24
- Built with gcc 4.8
- The testing program uses CUnit 2.1 (basic interface)

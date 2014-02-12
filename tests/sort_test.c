#include <stdio.h>
#include <stdlib.h>

#include "CUnit/Basic.h"

#include "sort.h"
#include "bubblesort.h"
#include "combsort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selectionsort.h"
#include "shellsort.h"

#define SIZE 10

#define CPY_SORT_CHECK(array, type, sortfct, cmpfct) int typesize = sizeof(type); \
  type* p = malloc(SIZE * typesize);\
  memcpy(p, array, SIZE * typesize); \
  sortfct(p, SIZE, typesize, cmpfct); \
  CU_ASSERT_TRUE(issorted(p, SIZE, typesize, cmpfct)); \
  free(p);

#define TEST_NULL_CMPFCT(sortfct) int memsize = SIZE * sizeof(int); \
  int* p = malloc(memsize); \
  memcpy(p, intarray, memsize); \
  sortfct(p, SIZE, sizeof(int), NULL); \
  /* No errors, the test passed */ \
  free(p);

#define TEST_NULL_ARRAY(sortfct) sortfct(NULL, SIZE, sizeof(int), compare_int); \
  /* No errors, the test passed */

/*
 *
 * Data for the tests
 *
 */
typedef struct s_dim2 {
  int x, y;
} dim2_t;

const int intarray[SIZE] = {8, -2, 20, -1, 0, 7, 9, 7, 14, -10};
const float floatarray[SIZE] = {2.3, 9.0, 2e12, 3.14159, -7.43, 42.0, 8.1, 32.001, 32.000001, -30};
const dim2_t dim2array[SIZE] = {{0, 0}, {-3, 8}, {14, 90}, {-4, 16}, {1, 7}, {2, 0}, {0, 0}, {8, 3}, {8, 7}, {12, 6}};

int compare_int(const void* i1, const void* i2) {
  return *((int*) i1) - *((int*) i2);
}

int compare_float(const void* f1, const void* f2) {
  return *((float*) f1) - *((float*) f2);
}

// Compares x. If both x are equals, compares y
int compare_dim2(const void* d1, const void* d2) {
  dim2_t dim1, dim2;
  dim1 = *((dim2_t*) d1);
  dim2 = *((dim2_t*) d2);
  return (dim1.x == dim2.x) ? dim1.y - dim2.y : dim1.x - dim2.x;
}


/*
 *
 * CUnit Test Suite
 *
 */

int init_suite(void) {
  return 0;
}

int clean_suite(void) {
  return 0;
}

/*
 **********************************************
 **************** Toolkit suite ***************
 **********************************************
 */
/*
 * Test-to-pass
 */
void swap_TTP() {
  int p[2] = {1, 2};
  swap(&p[0], &p[1], sizeof(int));
  CU_ASSERT_EQUAL(p[0], 2);
  CU_ASSERT_EQUAL(p[1], 1);
}

void issorted_true_TTP() {
  int p[5] = {0, 1, 2, 3, 3};
  CU_ASSERT_TRUE(issorted(p, 5, sizeof(int), compare_int));
}

void issorted_false_TTP() {
  CU_ASSERT_FALSE(issorted((void*)intarray, SIZE, sizeof(int), compare_int));
}

/*
 * Test-to-fail
 */
void swap_null_TTF() {
  int p[2] = {1, 2};
  swap(&p[0], NULL, sizeof(int));
  // Nothing changed because the second pointer was NULL
  CU_ASSERT_EQUAL(p[0], 1);
  CU_ASSERT_EQUAL(p[1], 2);
}

void issorted_null_TTF() {
  int p[2] = {1, 2};
  issorted(NULL, 2, sizeof(int), compare_int);
  issorted(p, 2, sizeof(int), NULL);
  // No errors, the test passed
}

/*
 *************************************************
 **************** Bubblesort suite ***************
 *************************************************
 */
/*
 * Test-to-pass
 */
void bubblesort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, bubblesort, compare_int);
}

void bubblesort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, bubblesort, compare_float);
}

void bubblesort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, bubblesort, compare_dim2);
}

/*
 * Test-to-fail
 */
void bubblesort_nullarray_TTF() {
  TEST_NULL_ARRAY(bubblesort);
}

void bubblesort_nullfct_TTF() {
  TEST_NULL_CMPFCT(bubblesort);
}

/*
 ********************************************
 ************** Comb sort suite *************
 ********************************************
 */
/*
 * Test-to-pass
 */
void combsort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, combsort, compare_int);
}

void combsort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, combsort, compare_float);
}

void combsort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, combsort, compare_dim2);
}

/*
 * Test-to-fail
 */
void combsort_nullarray_TTF() {
  TEST_NULL_ARRAY(combsort);
}

void combsort_nullfct_TTF() {
  TEST_NULL_CMPFCT(combsort);
}

/*
 ******************************************
 ************* Heapsort suite *************
 ******************************************
 */
/*
 * Test-to-pass
 */
void heapsort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, heapsort, compare_int);
}

void heapsort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, heapsort, compare_float);
}

void heapsort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, heapsort, compare_dim2);
}

/*
 * Test-to-fail
 */
void heapsort_nullarray_TTF() {
  TEST_NULL_ARRAY(heapsort);
}

void heapsort_nullfct_TTF() {
  TEST_NULL_CMPFCT(heapsort);
}

/*
 ************************************************
 ************* Insertion sort suite *************
 ************************************************
 */
/*
 * Test-to-pass
 */
void insertionsort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, insertionsort, compare_int);
}

void insertionsort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, insertionsort, compare_float);
}

void insertionsort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, insertionsort, compare_dim2);
}

/*
 * Test-to-fail
 */
void insertionsort_nullarray_TTF() {
  TEST_NULL_ARRAY(insertionsort);
}

void insertionsort_nullfct_TTF() {
  TEST_NULL_CMPFCT(insertionsort);
}

/*
 ********************************************
 ************* Merge sort suite *************
 ********************************************
 */
/*
 * Test-to-pass
 */
void mergesort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, mergesort, compare_int);
}

void mergesort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, mergesort, compare_float);
}

void mergesort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, mergesort, compare_dim2);
}

/*
 * Test-to-fail
 */
void mergesort_nullarray_TTF() {
  TEST_NULL_ARRAY(mergesort);
}

void mergesort_nullfct_TTF() {
  TEST_NULL_CMPFCT(mergesort);
}

/*
 ********************************************
 ************* Quicksort suite *************
 ********************************************
 */
/*
 * Test-to-pass
 */
void quicksort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, quicksort, compare_int);
}

void quicksort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, quicksort, compare_float);
}

void quicksort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, quicksort, compare_dim2);
}

/*
 * Test-to-fail
 */
void quicksort_nullarray_TTF() {
  TEST_NULL_ARRAY(quicksort);
}

void quicksort_nullfct_TTF() {
  TEST_NULL_CMPFCT(quicksort);
}

/*
 ************************************************
 ************* Selection sort suite *************
 ************************************************
 */
/*
 * Test-to-pass
 */
void selectionsort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, selectionsort, compare_int);
}

void selectionsort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, selectionsort, compare_float);
}

void selectionsort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, selectionsort, compare_dim2);
}

/*
 * Test-to-fail
 */
void selectionsort_nullarray_TTF() {
  TEST_NULL_ARRAY(selectionsort);
}

void selectionsort_nullfct_TTF() {
  TEST_NULL_CMPFCT(selectionsort);
}

/*
 ********************************************
 ************* Shell sort suite *************
 ********************************************
 */
/*
 * Test-to-pass
 */
void shellsort_int_TTP() {
  CPY_SORT_CHECK(intarray, int, shellsort, compare_int);
}

void shellsort_float_TTP() {
  CPY_SORT_CHECK(floatarray, float, shellsort, compare_float);
}

void shellsort_struct_TTP() {
  CPY_SORT_CHECK(dim2array, dim2_t, shellsort, compare_dim2);
}

/*
 * Test-to-fail
 */
void shellsort_nullarray_TTF() {
  TEST_NULL_ARRAY(shellsort);
}

void shellsort_nullfct_TTF() {
  TEST_NULL_CMPFCT(shellsort);
}

/*
 ********************************************************
 ************************* Main *************************
 ********************************************************
 */
int main(void) {
  CU_pSuite pSuite = NULL;

  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /*
   * Toolkit suite
   */
  pSuite = CU_add_suite("Toolkit", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "swap_TTP", swap_TTP) == NULL ||
      CU_add_test(pSuite, "issorted_true_TTP", issorted_true_TTP) == NULL ||
      CU_add_test(pSuite, "issorted_false_TTP", issorted_false_TTP) == NULL ||
      CU_add_test(pSuite, "swap_null_TTF", swap_null_TTF) == NULL ||
      CU_add_test(pSuite, "issorted_null_TTF", issorted_null_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Bubble sort suite
   */
  pSuite = CU_add_suite("Bubble sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "bubblesort_int_TTP", bubblesort_int_TTP) == NULL ||
      CU_add_test(pSuite, "bubblesort_float_TTP", bubblesort_float_TTP) == NULL ||
      CU_add_test(pSuite, "bubblesort_struct_TTP", bubblesort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "bubblesort_nullarray_TTF", bubblesort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "bubblesort_nullfct_TTF", bubblesort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Comp sort suite
   */
  pSuite = CU_add_suite("Comb sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "combsort_int_TTP", combsort_int_TTP) == NULL ||
      CU_add_test(pSuite, "combsort_float_TTP", combsort_float_TTP) == NULL ||
      CU_add_test(pSuite, "combsort_struct_TTP", combsort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "combsort_nullarray_TTF", combsort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "combsort_nullfct_TTF", combsort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Heapsort suite
   */
  pSuite = CU_add_suite("Heapsort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "heapsort_int_TTP", heapsort_int_TTP) == NULL ||
      CU_add_test(pSuite, "heapsort_float_TTP", heapsort_float_TTP) == NULL ||
      CU_add_test(pSuite, "heapsort_struct_TTP", heapsort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "heapsort_nullarray_TTF", heapsort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "heapsort_nullfct_TTF", heapsort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Insertion sort suite
   */
  pSuite = CU_add_suite("Insertion sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "insertionsort_int_TTP", insertionsort_int_TTP) == NULL ||
      CU_add_test(pSuite, "insertionsort_float_TTP", insertionsort_float_TTP) == NULL ||
      CU_add_test(pSuite, "insertionsort_struct_TTP", insertionsort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "insertionsort_nullarray_TTF", insertionsort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "insertionsort_nullfct_TTF", insertionsort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Merge sort suite
   */
  pSuite = CU_add_suite("Merge sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "mergesort_int_TTP", mergesort_int_TTP) == NULL ||
      CU_add_test(pSuite, "mergesort_float_TTP", mergesort_float_TTP) == NULL ||
      CU_add_test(pSuite, "mergesort_struct_TTP", mergesort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "mergesort_nullarray_TTF", mergesort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "mergesort_nullfct_TTF", mergesort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Quicksort suite
   */
  pSuite = CU_add_suite("Quicksort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "quicksort_int_TTP", quicksort_int_TTP) == NULL ||
      CU_add_test(pSuite, "quicksort_float_TTP", quicksort_float_TTP) == NULL ||
      CU_add_test(pSuite, "quicksort_struct_TTP", quicksort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "quicksort_nullarray_TTF", quicksort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "quicksort_nullfct_TTF", quicksort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Selection sort suite
   */
  pSuite = CU_add_suite("Selection sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "selectionsort_int_TTP", selectionsort_int_TTP) == NULL ||
      CU_add_test(pSuite, "selectionsort_float_TTP", selectionsort_float_TTP) == NULL ||
      CU_add_test(pSuite, "selectionsort_struct_TTP", selectionsort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "selectionsort_nullarray_TTF", selectionsort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "selectionsort_nullfct_TTF", selectionsort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*
   * Shell sort suite
   */
  /*
  pSuite = CU_add_suite("Shell sort", init_suite, clean_suite);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(pSuite, "shellsort_int_TTP", shellsort_int_TTP) == NULL ||
      CU_add_test(pSuite, "shellsort_float_TTP", shellsort_float_TTP) == NULL ||
      CU_add_test(pSuite, "shellsort_struct_TTP", shellsort_struct_TTP) == NULL ||
      CU_add_test(pSuite, "shellsort_nullarray_TTF", shellsort_nullarray_TTF) == NULL ||
      CU_add_test(pSuite, "shellsort_nullfct_TTF", shellsort_nullfct_TTF) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  */

  // Run all tests using the CUnit Basic interface
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n");
  int num_failures = CU_get_number_of_failures();
  CU_cleanup_registry();
  return num_failures;
}

/*
 * File: bookstore.c
 *
 * Sort and display books using differents compare functions and sorting algorithms.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubblesort.h"
#include "mergesort.h"
#include "selectionsort.h"
#include "sort.h"

#define SIZE 5
#define BUFSIZE 64

struct book {
  char title[BUFSIZE];
  char author[BUFSIZE];
  int date;
};

void printbooks(struct book bs[]);
int author_comparator(const void* p1, const void* p2);
int title_comparator(const void* p1, const void* p2);
int date_comparator(const void* p1, const void* p2);

int main(void) {
  struct book books[5] = {{"The C Programming Language", "K&R", 1978},
			  {"Just for Fun: The Story of an Accidental Revolutionary", "Linus Torvals", 2001},
			  {"Managing Projects with GNU Make", "Robert Mecklenburg", 2004},
			  {"Pro Git", "Scott Chacon", 2009},
			  {"A Brief History of Time", "Stephen Hawking", 1998}};
  unsigned char input;
  int booksize = sizeof(struct book);
  do {
    printf("\na) Sort books by author\n"
	   "t) Sort books by title\n"
	   "d) Sort books by publication date\n"
	   "Your choice : ");
    if (scanf("%c", &input) != 1) {
      perror("scanf");
      return 1;
    }
    printf("\n");
    while (getchar() != '\n');
    switch (input) {
    case 'a':
    case 'A':
      // Sort by author using the merge sort algorithm
      mergesort(books, SIZE, booksize, author_comparator);
      printbooks(books);
      break;
    case 't':
    case 'T':
      // Sort by title using the selection sort algorithm
      selectionsort(books, SIZE, booksize, title_comparator);
      printbooks(books);
      break;
    case 'd':
    case 'D':
      // Sort by date of publication using the bubble sort algorithm
      bubblesort(books, SIZE, booksize, date_comparator);
      printbooks(books);
      break;
    case 'q':
    case 'Q': // Do nothing
      break;
    default:
      printf("\nInvalid choice!\n");
    }
  } while (input != 'q' && input != 'Q');
  return 0;
}

void printbooks(struct book bs[]) {
  int i;
  for (i = 0; i < SIZE; i++)
    printf("%s, %s (%d)\n", bs[i].author, bs[i].title, bs[i].date);
}

int author_comparator(const void* p1, const void* p2) {
  struct book b1, b2;
  b1 = *((struct book*) p1);
  b2 = *((struct book*) p2);
  return strcmp(b1.author, b2.author);
}

int title_comparator(const void* p1, const void* p2) {
  struct book b1, b2;
  b1 = *((struct book*) p1);
  b2 = *((struct book*) p2);
  return strcmp(b1.title, b2.title);
}

int date_comparator(const void* p1, const void* p2) {
  struct book b1, b2;
  b1 = *((struct book*) p1);
  b2 = *((struct book*) p2);
  return b1.date - b2.date;
}

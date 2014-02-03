CC = gcc
CFLAGS = -g -Wall -O3
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TESTDIR = tests
INCLUDES = -I$(INCDIR)
LIBFLAGS = -cruvs
OBJ = $(OBJDIR)/sort.o $(OBJDIR)/bubblesort.o $(OBJDIR)/bucketsort.o $(OBJDIR)/combsort.o $(OBJDIR)/countingsort.o $(OBJDIR)/heapsort.o $(OBJDIR)/insertionsort.o $(OBJDIR)/mergesort.o $(OBJDIR)/quicksort.o $(OBJDIR)/radixsort.o $(OBJDIR)/selectionsort.o $(OBJDIR)/shellsort.o
TESTFILE=$(TESTDIR)/sort_test
TARGETS = lib test

all: $(TARGETS)

lib: $(BINDIR)/libsort.a

$(BINDIR)/libsort.a: $(OBJ)
	@[ -d $(BINDIR) ] || mkdir $(BINDIR)
	@echo "Creating $@"
	@ar $(LIBFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

build-tests: $(BINDIR)/libsort.a
	@echo "Compiling $(TESTFILE).c"
	@$(CC) $(CFLAGS) $(INCLUDES) $(TESTFILE).c -o $(TESTFILE) -L$(BINDIR) -lsort -lcunit

test: build-tests
	@echo "Running $(TESTFILE)"
	@$(TESTFILE)

clean: clean_tmp
	rm -rf $(OBJDIR)

clean_tests:
	rm -f $(TESTFILE)

clean_tmp:
	rm -f *~ $(SRCDIR)/*~ $(INCDIR)/*~ $(TESTDIR)/*~

distclean mrproper veryclean: clean clean_tests
	rm -rf $(BINDIR)

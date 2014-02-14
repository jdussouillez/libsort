CC = gcc
CFLAGS = -g -Wall -O3
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TESTDIR = tests
EXDIR = samples
INCLUDES = -I$(INCDIR)
LIBFLAGS = -cruvs
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TESTFILE=$(TESTDIR)/sort_test
TARGETS = lib test samples

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

samples:
	make -C $(EXDIR)

clean: clean_tmp
	rm -rf $(OBJDIR)
	make clean -C $(EXDIR)

clean_tests:
	rm -f $(TESTFILE)

clean_tmp:
	rm -f *~ $(SRCDIR)/*~ $(INCDIR)/*~ $(TESTDIR)/*~
	make clean_tmp -C $(EXDIR)

distclean mrproper veryclean: clean clean_tests
	rm -rf $(BINDIR)
	make distclean -C $(EXDIR)

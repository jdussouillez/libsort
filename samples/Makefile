CC = gcc
CFLAGS = -g -W -O3
LIB = -I../include -L../bin -lsort
SRC = $(wildcard *.c)
EXEC = $(SRC:.c=) # Remove the extension ".c"
TARGETS = build

all: $(TARGETS)

build:
	@if [ ! -e ../bin/libsort.a ]; then \
		echo "You have to build the lib first (make -C ../)"; \
		exit 2; \
	fi;
	@$(foreach f, $(EXEC), \
		echo "Compiling $f"; \
		$(CC) $(CFLAGS) $(f).c -o $(f) $(LIB); \
	)

clean: clean_tmp
	@$(foreach f, $(EXEC), \
		rm -vf $f; \
	)

clean_tmp:
	@rm -vf *~

distclean mrproper veryclean: clean

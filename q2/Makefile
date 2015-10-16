CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

SRCS_common = testdriver.h testdriver.c

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $(SRCS_common) $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $(SRCS_common) $@.c

clean:
	$(RM) $(EXEC) *.o perf.*

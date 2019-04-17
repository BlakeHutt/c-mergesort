CC=gcc
CFLAGS= -Wall -w -g -lm

all: merge.c iterativeMerge.c recursiveMerge.c
		$(CC) $(CFLAGS) -o mergeSort merge.c
		$(CC) $(CFLAGS) -o iterative iterativeMerge.c
		$(CC) $(CFLAGS) -o recursive recursiveMerge.c

clean:
	rm -f mergeSort
	rm -f iterative
	rm -f recursive


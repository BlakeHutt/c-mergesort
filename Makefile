CC=gcc
CFLAGS= -Wall -w -g -lm

main: merge.c
	$(CC) $(CFLAGS) -o mergeSort merge.c

all: merge.c iterativeMerge.c recursiveMerge.c mergeSmallOut.c
		$(CC) $(CFLAGS) -o mergeSort merge.c
		$(CC) $(CFLAGS) -o iterative iterativeMerge.c
		$(CC) $(CFLAGS) -o recursive recursiveMerge.c
		$(CC) $(CFLAGS) -o small mergeSmallOut.c

small:	mergeSmallOut.c
		$(CC) $(CFLAGS) -o small mergeSmallOut.c
clean:
	rm -f mergeSort
	rm -f iterative
	rm -f recursive
	rm -f small


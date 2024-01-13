# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CFLAGS=-I. -Wall -Werror

test_ll: test_ll.c ll.c
	gcc -o test_ll test_ll.c ll.c $(CFLAGS)

shared:
	gcc $(CFLAGS) -c -fpic ll.c
	gcc $(CFLAGS) -shared -o libll.so ll.o

test_shared:
	gcc -o test_shared test_shared.c -lll -L. $(CFLAGS)
	LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH ./test_shared
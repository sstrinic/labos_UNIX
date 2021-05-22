CC = gcc
CFLAGS = -Wall
TARGETS = pr1 pr2 pr3 pr4

default:pr3

all: $(TARGETS)

pr1:pr1.o
	$(CC) $(CFLAGS) pr1.o -o pr1

pr2:pr2.o
	$(CC) $(CFLAGS) pr2.o -o pr2
             
pr3:pr3.o
	$(CC) $(CFLAGS) pr3.o -o pr3

pr4:pr4.o pr4_fn.o
	$(CC) $(CFLAGS) pr4.o pr4_fn.o -o pr4

pr4_fn:pr4_fn.o
	$(CC) $(CFLAGS) pr4_fn.o -o pr4_fn
	
clean:
	rm -f *.o *~ a.out $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) -c $<
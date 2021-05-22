CC = gcc
CFLAGS = -Wall
TARGETS = primjer2 primjer1 pr2_sa_fn

default:pr2_sa_fn

all: $(TARGETS)

primjer2:primjer2.o
	$(CC) $(CFLAGS) primjer2.o -o primjer2

primjer1:primjer1.o
	$(CC) $(CFLAGS) primjer1.o -o primjer1

pr2_sa_fn:pr2_sa_fn.o
	$(CC) $(CFLAGS) pr2_sa_fn.o -o pr2_sa_fn
	
clean:
	rm -f *.o *~ a.out $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) -c $<
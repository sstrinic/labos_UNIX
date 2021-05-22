CC = gcc
CLAFGS = -Wall

TARGETS = glavni1 glavni2

default: glavni2

all:$(TARGETS)

glavni1: glavni1.o
	$(CC) $(CFLAGS) glavni1.o -o glavni1

glavni2: glavni2.o fn.o
	$(CC) $(CFLAGS) glavni2.o fn.o -o glavni2

clean:
	rm -f *.o *~ a.out $(TARGETS)
	
.c.o:
	$(CC) $(CFLAGS) -c $<
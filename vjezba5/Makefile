CC = gcc
CFLAGS = -Wall
TARGETS = zad

default: zad
all: $(TARGETS)

zad:zad.o
	$(CC) $(CFLAGS) zad.o -o zad

clean:
	rm -f *.o a.out *~ $(TARGETS)
	
.c.o:
	$(CC) $(CFLAGS) -c $<
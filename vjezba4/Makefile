CC = /usr/bin/gcc
CFLAGS = -Wall

TARGETS = pinit1 pinit2

default: pinit1
all: $(TARGETS)

pinit1:pinit1.o
	$(CC) $(CFLAGS) pinit1.o -o pinit1
	
pinit2:pinit2.o
	$(CC) $(CFLAGS) pinit2.o -o pinit2

clean:
	rm -f *.o a.out *~ $(TARGETS)
	
.c.o:
	$(CC) $(CFLAGS) -c $<
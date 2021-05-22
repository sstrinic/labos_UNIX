CC = gcc
CFLAGS = -Wall
TARGETS = zad1 ls

default:ls
all: $(TARGETS)

zad1:zad1.o
	$(CC) $(CFLAGS) zad1.o -o zad1

ls:ls.o
	$(CC) $(CFLAGS) ls.o -o ls

clean:
	rm -f *.o a.out *~ $(TARGETS)
	
.c.o:
	$(CC) $(CFLAGS) -c $<
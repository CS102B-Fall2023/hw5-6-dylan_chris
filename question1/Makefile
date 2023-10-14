CC = gcc
CFLAGS = -I.

make: main.o sos.o 
	$(CC) $(CFLAGS) -o main.out main.o sos.o
sos.o: sos.c sos.h
	$(CC) $(CFLAGS) -c sos.c

main.o: main.c sos.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.out

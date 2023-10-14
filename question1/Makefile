CC = gcc
CFLAGS = -I.

make: main.o sos.o howbig.o 
	$(CC) $(CFLAGS) -o main.out main.o sos.o howbig.o
sos.o: sos.c sos.h
	$(CC) $(CFLAGS) -c sos.c

howbig.o: howbig.c howbig.c
	$(CC) $(CFLAGS) -c howbig.c


main.o: main.c sos.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.out

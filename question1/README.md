## Question 1

Write the SOS game that is playable by 2 players. More information can be found on: <a href="https://en.wikipedia.org/wiki/SOS_(game)">https://en.wikipedia.org/wiki/SOS_(game)</a>

Include the following requirements:
* The game should be split up into multiple files.
* The game should be compiled using a makefile. The game should be compiled with ```make```.
* The game should have a game board of 5x5.
* The number of SOS points should be counted per player.
* The game ends when the entire board is filled and the winner is declared.
* One should be able to do a rematch.
* Give the option for a player to play against the computer. The computer doesn't need to be smart. 
* Print the current state of the game after each turn.

This question is 100 points (50 points for quality & 50 points for output).

Please answer the bonus parts of this question in the question2 folder.

Compilation Steps:

CC = gcc
CFLAGS = -I.

make: main.o sos.o  
	$(CC) $(CFLAGS) -o main.out main.o sos.o howbig.o
sos.o: sos.c sos.h
	$(CC) $(CFLAGS) -c sos.c
main.o: main.c sos.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.out

Output:

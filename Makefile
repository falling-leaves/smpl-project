# makefile

CC = gcc

main: main.o
	$(CC) -o smpl main.o

main.o: main.c
	$(CC) -c main.c

clean:
	rm -rf *.o ./.tasks

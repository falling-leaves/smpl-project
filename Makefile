# makefile

CC = gcc
INC = -I./inc
OBJ = obj

objects = $(addprefix $(OBJ)/, main.o)

main : $(objects)
	$(CC) $(objects) -o $@

obj/main.o : main.c
	$(CC) -c main.c -o $@

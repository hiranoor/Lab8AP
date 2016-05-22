
OBJS =  main.o vector.o matrix.o
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS = -lm

main.o: main.cc vector.h matrix.h
	$(CC) -c main.cc


vector.o: vector.cc vector.h
	$(CC) -c vector.cc
	
matrix.o: matrix.cc matrix.h
	$(CC) -c matrix.cc
	
	
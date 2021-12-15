CC = gcc
AR = ar
FLAGS = -Wall -g

all: libalgo.so stringProg

libalgo.so: algo.o
	$(CC) -shared -o libalgo.so algo.o

algo.o: algo.h algo.c
	$(CC) $(FLAGS) -c algo.c 

main.o: algo.h main.c
	$(CC) $(FLAGS) -c main.c

stringProg: main.o libalgo.so
	$(CC) $(FLAGS) -o stringProg main.o ./libalgo.so

.PHONY: clean all

clean:
	rm -f *.o *.so stringProg libalgo
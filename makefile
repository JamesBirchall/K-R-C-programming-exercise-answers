CFLAGS= -Wall -g

all: kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter2answers.c kandrcchapter1answers.c main.c -o kandrexercises

clean:
	rm -f kandrexercises kandrcchapter2answers.o kandrcchapter1answers.o

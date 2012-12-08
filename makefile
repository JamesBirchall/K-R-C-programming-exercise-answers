CFLAGS= -Wall -g

all: kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter4answers.c kandrcchapter3answers.c kandrcchapter2answers.c kandrcchapter1answers.c main.c -lm -std=c99 -o kandrexercises

clean:
	rm -f kandrexercises kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o

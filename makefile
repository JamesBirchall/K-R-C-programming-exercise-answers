CFLAGS= -Wall -g

all: kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter5answers.c polishcalc.c kandrcchapter4answers.c kandrcchapter3answers.c kandrcchapter2answers.c kandrcchapter1answers.c main.c -lm -std=c99 -o kandrexercises

clean:
	rm -f kandrexercises kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o

CFLAGS= -Wall -g

all:kandrbtests
	gcc kandrcchapter1answers.c -o kandrcchapter1answers

clean:
	rm -f kandrcchapter1answers

CFLAGS= -Wall 

all:   kandrcchapter7answers.o kandrcchapter6answers.o kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter7answers.c kandrcchapter6answers.c kandrcchapter5answers.c polishcalc.c kandrcchapter4answers.c kandrcchapter3answers.c kandrcchapter2answers.c kandrcchapter1answers.c main.c -lm -g -std=c99 -o kandrexercises

upper:   kandrcchapter7answers.o kandrcchapter6answers.o kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter7answers.c kandrcchapter6answers.c kandrcchapter5answers.c polishcalc.c kandrcchapter4answers.c kandrcchapter3answers.c kandrcchapter2answers.c kandrcchapter1answers.c main.c -lm -g -std=c99 -o upper

lower:   kandrcchapter7answers.o kandrcchapter6answers.o kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o main.o
	gcc kandrcchapter7answers.c kandrcchapter6answers.c kandrcchapter5answers.c polishcalc.c kandrcchapter4answers.c kandrcchapter3answers.c kandrcchapter2answers.c kandrcchapter1answers.c main.c -lm -g -std=c99 -o lower

clean:
	rm -f kandrexercises kandrchapter7answers.o kandrcchapter6answers.o kandrcchapter5answers.o polishcalc.o kandrcchapter4answers.o kandrcchapter3answers.o kandrcchapter2answers.o kandrcchapter1answers.o

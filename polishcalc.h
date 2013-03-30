// polishcalc.h

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);
int getopandminus(char[]);

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

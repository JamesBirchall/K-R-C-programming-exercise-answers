// polishcalc.h

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

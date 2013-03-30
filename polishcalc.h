// polishcalc.h

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);
int getopandminus(char[]);
void printTop();
void duplicate();
void swap();
void clear();
void printstack();
void functionUsed(char[]);
void initVariables();
void printAllVariables();
void storeVariable(char[]);
void clearVariables(char[]);

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define FUNCTION '1'
#define VARIABLE '2'

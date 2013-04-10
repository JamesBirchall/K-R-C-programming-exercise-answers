#if !defined(_KANDREX_H5)
#define _KANDREX_H5

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h> 

int ex5_1();
int ex5_2();
int ex5_3();
int ex5_4();
int ex5_5();
int ex5_6();

int getintch5(int*);
int getfloatch5(float*);
void ungetch5(int);
int getch5(void);
int strcatch5(char *, char *);
int strendch5(char *, char *);
int strncopych5(char *, char *, int);
int strncatch5(char *, char *, int);
int strncmpch5(char *, char *, int);
int getlinech5(char *, char*);
int atoich5(char *);
void itoach5(int, char *);
void reversech5(char *);
int strindexch5(char *, char *);
int getopch5(char *);

#endif

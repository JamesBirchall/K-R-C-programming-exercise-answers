#if !defined(_KANDREX_H5)
#define _KANDREX_H5

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int ex5_1();
int ex5_2();
int ex5_3();
int ex5_4();
int ex5_5();
int ex5_6();
int part5_6program();
int part5_6program_2(); //ex 5_7 actually -.-
int ex5_8();
int ex5_9();
int ex5_10(int, char *[]);
int ex5_11(int, char *[]);
int ex5_12(int, char *[]);

void entabch5(char*, char*, int);
void detabch5(char*, char*, int);
int dayofyear(int, int, int);
int monthday(int, int, int *, int *);
int dayofyear_p(int, int, int);
int monthday_p(int, int, int *, int *);
int getintch5(int*);
int getfloatch5(float*);
void ungetch5(int);
int getch5(void);
int strcatch5(char *, char *);
int strendch5(char *, char *);
int strncopych5(char *, char *, int);
int strncatch5(char *, char *, int);
int strncmpch5(char *, char *, int);
int getlinech5(char *, int);
int atoich5(char *);
void itoach5(int, char *);
void reversech5(char *);
int strindexch5(char *, char *);
int getopch5(char *);
int readlinesch5(char **, int);
void writelinesch5(char **, int);
void qsortch5(char **, int, int);
void swapch5(char **, int, int);
int getstringlinech5(char [], int);
int readlinesch5_2(char **, int, char *);

#endif

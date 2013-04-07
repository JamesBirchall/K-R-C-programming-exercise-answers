#if !defined(_KANDREX_H4)
#define _KANDREX_H4

#include <stdio.h>
#include <ctype.h>

int ex4_1();
int ex4_2();
int ex4_2_2();
int ex4_3();
int ex4_4();
int ex4_5();
int ex4_6();
int ex4_7();
int ex4_8();
int ex4_9();
int ex4_10();
int ex4_11();
int ex4_12();
int ex4_13();

int getLineByString(char[], int);
int stringIndex(char[], char[]);
int stringIndexRight(char[], char[]);
double stringtodouble(char[]);
int stringtointeger(char[]);
double stringwithexponenttodouble(char[]);
int polishcalc();
void printd410(int);
void qsort2(int[], int, int);
void swap2(int[], int, int);
void recursiveReverseString(char[]);
void itoach4(int);

#define swapper(t,x,y) t z = x; x = y; y = z;

#endif

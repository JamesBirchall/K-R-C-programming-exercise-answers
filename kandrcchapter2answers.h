#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <math.h>

void ex2_1();
void ex2_2();
void ex2_3(char[]);
void ex2_4(char[], char[]);
int ex2_5(char[], char[]);
void ex2_6();
void ex2_7();
void ex2_8();
void ex2_9();
void ex2_10();

unsigned int getBits(unsigned int, int, int);
unsigned int setBits(unsigned int, int, int,unsigned  int);
unsigned int invertBits(unsigned int, int, int);
unsigned int rightRotate(unsigned int, int);
int bitCountOriginal(unsigned x);
int bitCountNew(unsigned x);
void lowerString(char[]);
void printBinary(unsigned int);
int binsearch(int, int[], int);

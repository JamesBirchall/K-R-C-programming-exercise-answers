#if !defined(_KANDREX_H1)
#define _KANDREX_H1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getstringline(char[], int);

int getstringlineremovetrail(char charArray[], int limit);

void copyString(char[], char[]);

void copyStringReverse(char to[], char from[], int len);

void detab(char to[], char from[], int tabsize);

void entab(char to[], char from[], int tabsize);

#endif

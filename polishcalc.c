#include "polishcalc.h"

int stackPointer = 0;
double value[MAXVAL];

char buffer[100];
int bufferfreeposition = 0;

void push(double f){
  if(stackPointer < MAXVAL)
    value[stackPointer++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void){

  if(stackPointer > 0)
    return value[--stackPointer];
  else{
    printf("error: stack empty\n");
    return 0.0f;
  }
}

int getop(char s[]){

  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t');  //skip whitespace

  s[1] = '\0';

  if(!isdigit(c) && c != '.')
    return c; //likely an operand

  i = 0;

  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()));

  if(c == '.')
    while(isdigit(s[++i] = c = getch()));

  s[i] = '\0';

  if(c != EOF)
    ungetch(c);

  return NUMBER;  //returns '0' in integer form to signify its an operand vs operator
}

int getch(void){
  return (bufferfreeposition > 0) ? buffer[--bufferfreeposition] : getchar();
}

void ungetch(int c){
  if(bufferfreeposition >= 100)
    printf("ungetch: too many characters\n");
  else
    buffer[bufferfreeposition++] = c;
}

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

int getopandminus(char s[]){

  //need to deal with minus symbol in here
  //to do this lets check for minus and if so get the rest of the
  //number and then sign it up

  int i, c, nextValue;
  i = 0;

  
  while((s[0] = c = getch()) == ' ' || c == '\t');  //skip whitespace

  s[1] = '\0'; 

  //check for digit, decimal or minus symbol
  if(!isdigit(c) && c != '.' && c != '-'){
    printf("\nReturning: %c", c);
    return c; //likely an operand
  }

  

  //check number after minus
  if(c == '-'){
    //get next value after minus sign
    nextValue = getch();
    //check for digit or decimal point
    if(!isdigit(nextValue) &&  nextValue != '.'){
      //is there isn't  valid number or decimal point return as its likely a minus symbol
      printf("\nReturning after minus symbol...: %c", c);
      return c;
    }
    //else get next Value
    c = nextValue;
    printf("\nSetting c to next value: %c", c);
    i++;
    s[i] = c;
  }

  if(isdigit(c)){
      while(isdigit(s[++i] = c = getch())){
        printf("\nGetting next digit...: %c", c);
      }
  }


  if(c == '.'){
    while(isdigit(s[++i] = c = getch())){
      printf("\nGetting next digit...: %c", c);
    }

  }

  s[i] = '\0';

  if(c != EOF)
    ungetch(c);

  int j;
  for(j = 0; j < strlen(s); j++){
    printf("\nSymbol: %c", s[j]);
  }

  printf("\nReturning end of function NUMBER: %f", atof(s));

  return NUMBER;  //returns '0' in integer form to signify its an operand vs operator
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

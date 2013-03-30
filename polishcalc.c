#include "polishcalc.h"

int stackPointer = 0;
double value[MAXVAL];

char buffer[100];
int bufferfreeposition = 0;

void printstack(){
  if(stackPointer > 0){
    int count = stackPointer;
    while(--count >= 0)
      printf("\nStack position [%3d] : %f", count, value[count]);
  }
  else
    printf("\nerror: stack empty");
}

void printTop(){
  if(stackPointer > 0)
    printf("\nTop of stack: %f", value[stackPointer-1]);
  else
    printf("\nerror: nothing in stack");
}

void duplicate(){
  if(stackPointer > 0){
    double f = pop();
    push(f);
    push(f);
  }
  else
    printf("\nerror: cannot duplicate as stack empty");
}

void swap(){
  if(stackPointer > 1){
    float f = pop();
    float g = pop();
    push(f);
    push(g);
  }
  else
    printf("\nerror: stack doesn't hold 2 values to swap");
}

void clear(){
  if(stackPointer > 0){
    stackPointer = 0;
    printf("\nstack cleared");
  }
  else
    printf("\nerror: stack already empty");
}


void push(double f){
  if(stackPointer < MAXVAL)
    value[stackPointer++] = f;
  else
    printf("\nerror: stack full, can't push %g\n", f);
}

double pop(void){

  if(stackPointer > 0)
    return value[--stackPointer];
  else{
    printf("\nerror: stack empty\n");
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
    return c; //likely an operand
  }

  

  //check number after minus
  if(c == '-'){
    //get next value after minus sign
    nextValue = getch();
    //check for digit or decimal point
    if(!isdigit(nextValue) &&  nextValue != '.'){
      //is there isn't  valid number or decimal point return as its likely a minus symbol
      return c;
    }
    //else get next Value
    c = nextValue;
    i++;
    s[i] = c;
  }

  if(isdigit(c)){
      while(isdigit(s[++i] = c = getch())){
        ;
      }
  }


  if(c == '.'){
    while(isdigit(s[++i] = c = getch())){
      ;
    }

  }

  s[i] = '\0';

  if(c != EOF)
    ungetch(c);

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
    printf("\nungetch: too many characters\n");
  else
    buffer[bufferfreeposition++] = c;
}

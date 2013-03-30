#include "polishcalc.h"

int stackPointer = 0;
double value[MAXVAL];

char buffer[100];
int bufferfreeposition = 0;

double variables[26];

void clearVariables(char s[]){
  int i;
  for(i = 0; i < 26; i++)
    variables[i] = 0.0f;
}

void storeVariable(char s[]){
  
  //store if empty, recall if not!
  int value = s[0] - 'A';
  if(variables[value] == 0.0f){
    float temp = pop();
    printf("\nPopping stack & setting %c, with %f\n", s[0], temp);
    variables[value] = temp;
  }
  else{
    printf("\nPushing variable onto stack\n");
    push(variables[value]);
  }
}

void printAllVariables(){
  int i;
  for(i = 0; i < 26; i++)
    printf("\nVariable [%c]: %f", i+'A', variables[i]);

  printf("\n");
}

void initVariables(){
  int i;
  for(i = 0; i < 26; i++){
    variables[i] = 0.0f;
  }
}

void functionUsed(char s[]){
  if(0 == strcmp(s, "exp"))
    push(exp(pop()));
  else if(0 == strcmp(s, "pow")){
    if(stackPointer > 1){
      // take last item off and store temp as power is not commutitive
      float op2 = pop();
      push(pow(pop(), op2));
    }
    else{
      printf("\nerror: not enough values in stack\n");
    }
  }
  else if(0 == strcmp(s, "sin")){
    if(stackPointer > 0)
      push(sin(pop()));
    else
      printf("\nerror: no values on stack");
  }
  else if(0 == strcmp(s, "cos")){
    if(stackPointer > 0)
      push(cos(pop()));
    else
      printf("\nerror: no values on stack");
  }
  else
    printf("\nerror: function unknown");
}

void printstack(){
  if(stackPointer > 0){
    int count = stackPointer;
    while(--count >= 0)
      printf("\nStack position [%3d] : %f", count, value[count]);
  }
  else
    printf("\nerror: stack empty");

  printf("\n");
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

  int i, c, nextValue;
  i = 0;

  
  while((s[0] = c = getch()) == ' ' || c == '\t');  //skip whitespace

  s[1] = '\0'; 

  if(isalpha(c) && isupper(c)){
    return VARIABLE;
  }

  //check for digit, decimal or minus symbol
  if(!isdigit(c) && c != '.' && c != '-'){
    if(isalpha(c)){
      int nextValue = getch();
      if(isalpha(nextValue)){
        s[0] = c;
        s[1] = nextValue;
        i = 1;
        while(isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        if(c != EOF)
          ungetch(c);

        return FUNCTION;
      }
    }

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

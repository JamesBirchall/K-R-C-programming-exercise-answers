#include "kandrcchapter4answers.h"
#include "polishcalc.h"

char lines[1000];
int linesCounter;

int ex4_12(){


  return 0;
}

void printd410(int number){
  if (number < 0){
    putchar('-');
    number = ~number;
  }

  if(number / 10){
    printd410(number / 10);
  }

  putchar(number % 10 +'0');
}

int ex4_11(){

  char stringed[] = "2345";

  printf("%c", getop2(stringed));

  return 0;
}

int ex4_10(){

  //adds in % operator and ability to deal with negative numbers entered
  int type;
  double op2;
  char myString[100];

  initVariables();

while(getLineByString(lines, 1000) != 0){

  //added in v's, so can say A and if empty value gets popped into it
  //also provide a mecanism for clearing the variable to 0 again
  while(( type= getopandminus2(myString)) != EOF){
    switch (type){
      case '0':
        printf("\nPushing number: %f \n", atof(myString));
        push(atof(myString));
        break;
      case '+':
        printf("\nAdding...\n");
        push(pop() + pop());
        break;
      case '*':
        printf("\nMultiplying...\n");
        push(pop() * pop());
        break;
      case '-':
        printf("\nSubtracting...\n");
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        printf("\nDividing...\n");
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("\nerror: divide by zero\n");
        break;
      case '%':
        printf("\nTaking modulus...\n");
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case 'e':
        printf("\nPopping off top result: %.8g\n", pop());
        break;
      case 't':
        printf("\nPrinting top of stack...\n");
        printTop();
        break;
      case 'd':
        printf("\nDuplicating item on top of stack...\n");
        duplicate();
        break;
      case 's':
        printf("\nSwapping top 2 items on stack...\n");
        swap();
        break;
      case 'c':
        printf("\nClearing whole stack...\n");
        clear();
        break;
      case 'a':
        printf("\nPrinting all of the stack...\n");
        printstack();
        break;
      case 'v':
        printf("\nPrinting all variables...\n");
        printAllVariables();
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
        case '1':
          printf("\nTrying to run function on values...\n");
         functionUsed(myString);
         break;
        case '2':
          printf("\nVariable...\n");
          storeVariable(myString);
          break;
       case '$':
          printf("\nClearing variables list...\n");
          clearVariables(myString);
         break;
       case '\n':
         printf("\n");
          break;
        default:
          printf("\nerror: unknown command %s\n", myString);
          break;
      }
    }
  }

  return 0;
}

int ex4_9(){

  char ch;

  ungetch(EOF);

  while((ch = getch()) != EOF){
    putchar(ch);
  }

  return 0;
}

int ex4_8(){
  //do not see the point in this exercise.  Essentially
  //its taking the buffer and making it a single value
  //size only.  Not 100 which its set to by defauly in
  //polish.c.  The checks then simply look for the single
  //placeholder to contain something not an identifier for
  //holding nothing. If it does its full!

  return 0;
}

int ex4_7(){

  char myString[] = "String of something I have.";
  int characterValue;

  myString[26] = EOF;

  ungets(myString);
  
  printf("\n");

  while((characterValue = getch()) != EOF){
    putchar(characterValue);
  }

  printf("\n");

  return 0;
}

int ex4_6(){

  //adds in % operator and ability to deal with negative numbers entered
  int type;
  double op2;
  char myString[100];

  initVariables();

  //added in v's, so can say A and if empty value gets popped into it
  //also provide a mecanism for clearing the variable to 0 again

  while(( type= getopandminus(myString)) != EOF){
    switch (type){
      case '0':
        printf("\nPushing number: %f \n", atof(myString));
        push(atof(myString));
        break;
      case '+':
        printf("\nAdding...\n");
        push(pop() + pop());
        break;
      case '*':
        printf("\nMultiplying...\n");
        push(pop() * pop());
        break;
      case '-':
        printf("\nSubtracting...\n");
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        printf("\nDividing...\n");
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("\nerror: divide by zero\n");
        break;
      case '%':
        printf("\nTaking modulus...\n");
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case 'e':
        printf("\nPopping off top result: %.8g\n", pop());
        break;
      case 't':
        printf("\nPrinting top of stack...\n");
        printTop();
        break;
      case 'd':
        printf("\nDuplicating item on top of stack...\n");
        duplicate();
        break;
      case 's':
        printf("\nSwapping top 2 items on stack...\n");
        swap();
        break;
      case 'c':
        printf("\nClearing whole stack...\n");
        clear();
        break;
      case 'a':
        printf("\nPrinting all of the stack...\n");
        printstack();
        break;
      case 'v':
        printf("\nPrinting all variables...\n");
        printAllVariables();
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      case '1':
        printf("\nTrying to run function on values...\n");
        functionUsed(myString);
        break;
      case '2':
        printf("\nVariable...\n");
        storeVariable(myString);
        break;
      case '$':
        printf("\nClearing variables list...\n");
        clearVariables(myString);
        break;
      case '\n':
        printf("\n");
        break;
      default:
        printf("\nerror: unknown command %s\n", myString);
        break;
    }
  }

  return 0;
}

int ex4_5(){

  //adds in % operator and ability to deal with negative numbers entered
  int type;
  double op2;
  char myString[100];

  while(( type= getopandminus(myString)) != EOF){
    switch (type){
      case '0':
        printf("\nPushing number: %f \n", atof(myString));
        push(atof(myString));
        break;
      case '+':
        printf("\nAdding...\n");
        push(pop() + pop());
        break;
      case '*':
        printf("\nMultiplying...\n");
        push(pop() * pop());
        break;
      case '-':
        printf("\nSubtracting...\n");
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        printf("\nDividing...\n");
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("\nerror: divide by zero\n");
        break;
      case '%':
        printf("\nTaking modulus...\n");
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case 'e':
        printf("\nPopping off top result: %.8g\n", pop());
        break;
      case 't':
        printf("\nPrinting top of stack...\n");
        printTop();
        break;
      case 'd':
        printf("\nDuplicating item on top of stack...\n");
        duplicate();
        break;
      case 's':
        printf("\nSwapping top 2 items on stack...\n");
        swap();
        break;
      case 'c':
        printf("\nClearing whole stack...\n");
        clear();
        break;
      case 'a':
        printf("\nPrinting all of the stack...\n");
        printstack();
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      case '1':
        printf("\nTrying to run function on values...\n");
        functionUsed(myString);
        break;
      case '\n':
        printf("\n");
        break;
      default:
        printf("\nerror: unknown command %s\n", myString);
        break;
    }
  }


  return 0;
}


int ex4_4(){

  //adds in % operator and ability to deal with negative numbers entered
  int type;
  double op2;
  char myString[100];

  while(( type= getopandminus(myString)) != EOF){
    switch (type){
      case '0':
        printf("\nPushing number: %f ", atof(myString));
        push(atof(myString));
        break;
      case '+':
        printf("\nAdding...");
        push(pop() + pop());
        break;
      case '*':
        printf("\nMultiplying...");
        push(pop() * pop());
        break;
      case '-':
        printf("\nSubtracting...");
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        printf("\nDividing...");
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("\nerror: divide by zero\n");
        break;
      case '%':
        printf("\nTaking modulus...");
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case 'e':
        printf("\nPopping off top result: %.8g\n", pop());
        break;
      case 't':
        printf("\nPrinting top of stack...");
        printTop();
        break;
      case 'd':
        printf("\nDuplicating item on top of stack...");
        duplicate();
        break;
      case 's':
        printf("\nSwapping top 2 items on stack...");
        swap();
        break;
      case 'c':
        printf("\nClearing whole stack...");
        clear();
        break;
      case 'a':
        printf("\nPrinting all of the stack...");
        printstack();
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      case '\n':
        printf("\n");
        break;
      default:
        printf("\nerror: unknown command %s\n", myString);
        break;
    }
  }


  return 0;
}


int ex4_3(){

  //adds in % operator and ability to deal with negative numbers entered
  int type;
  double op2;
  char myString[100];

  while(( type= getopandminus(myString)) != EOF){
    switch (type){
      case '0':
        printf("\nPushing number: %f ", atof(myString));
        push(atof(myString));
        break;
      case '+':
        printf("\nAdding...");
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: divide by zero\n");
        break;
      case '%':
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case '\n':
        printf("\n\t%.8g\n", pop());
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      default:
        printf("error: unknown command %s\n", myString);
        break;
    }
  }


  return 0;
}

int polishcalc(){

  int type;
  double op2;
  char myString[100];

  while(( type= getop(myString)) != EOF){
    switch (type){
      case '0':
        push(atof(myString));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: divide by zero\n");
        break;
      case '\n':
        printf("\n\t%.8g\n", pop());
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      default:
        printf("error: unknown command %s\n", myString);
        break;
    }
  }
  return 0;
}

int ex4_2_2(){
  
  char myString1[] = "123.3E5";
  char myString2[] = "1.5E-5";
  char myString3[] = "451.5E-9";

  double myDouble = 0.0;
  printf("My String: %s\n", myString1);
  myDouble = stringwithexponenttodouble(myString1);
  printf("My Double: %.15f\n", myDouble);


  myDouble = 0.0;
  printf("My String: %s\n", myString2);
  myDouble = stringwithexponenttodouble(myString2);
  printf("My Double: %.15f\n", myDouble);

  myDouble = 0.0;
  printf("My String: %s\n", myString3);
  myDouble = stringwithexponenttodouble(myString3);
  printf("My Double: %.15f\n", myDouble);
  
  return -1;
}

double stringwithexponenttodouble(char myString[]){
  double value, power, exponent;
  int i, sign;

  sign = 1;

  for(i = 0; isspace(myString[i]); i++);

  // remove space in front of word
  //take all numbers same as before and store in value

  for(value = 0.0; isdigit(myString[i]); i++)
    value = 10.0 * value + (myString[i] - '0');

  //skip over decimal point
  if(myString[i] == '.')
    i++;

  //take parts afterwards in same way
  for(power = 1.0; isdigit(myString[i]); i++){
    value = 10.0 * value + (myString[i] - '0');
    power *= 10;
  }

  //look for upper/lowercase E, if not here then quit with error message
  if(tolower(myString[i]) == 'e')
    i++;
  else
    printf("\nError - Not valid scientific notation x.xxx[E|e][-]x\n");    

  //check for minus sign - if exists make sign
  if(myString[i] == '-'){
    sign  = -1;
    i++;
  }

  //finally process exponent figure either multiply by 10 or divide by 10 depending on sign
  if(isdigit(myString[i])){
    for(exponent = 0.0; isdigit(myString[i]); i++){
      //exponent is then - value and flipped by sign
      exponent = 10.0 * exponent + (myString[i] - '0');
    }
  }

  //now we take exponent and come up with multiplier figure
  float multiplier = 1.0;
   
  //loop through exponent until it reach zero, multiplying multipler by 10 each time
  while(exponent != 0){
    if(sign == 1)
      multiplier *= 10;
    else
      multiplier /= 10;
    exponent--;
  }

  return (value/power)*multiplier;
}

int stringtointeger(char myString[]){
  return (int) stringtodouble(myString);
}

double stringtodouble(char myString[]){
  double val, power;
  int i, sign;

  for(i = 0; isspace(myString[i]); i++); /* Skips whitespace */

  sign = (myString[i] == '-') ? -1 : 1; 

  if(myString[i] == '+' || myString[i] == '-')
    i++;

  for(val = 0.0; isdigit(myString[i]); i++)
    val = 10.0 * val + (myString[i] - '0');

  if(myString[i] == '.')
    i++;
  
  for(power = 1.0; isdigit(myString[i]); i++){
    val = 10.0 * val + (myString[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}

int ex4_1(){
  int MAXLINE = 1000;

  char pattern[] = "test";

  char line[MAXLINE]; //no need to \0 out, getinput will do this for us

  int found = 0;
  int returnedIndexValue = 0;

  while(getLineByString(line, MAXLINE) > 0){
    returnedIndexValue = stringIndexRight(line, pattern);
    if(returnedIndexValue >= 0){
      printf("Match found at location %d\n", returnedIndexValue);
      printf("%s", line);
      ++found;
    }
  }
  printf("\n");
  return found;
}

int getLineByString(char returnString[], int characterLimit){
  
  int i = 0;
  int c;

  while(--characterLimit > 0 && (c= getchar()) != EOF && c != '\n')
    returnString[i++] = c;
  if(c == '\n')
    returnString[i++] = c;
  returnString[i] = '\0';

  return i;
}

int stringIndexRight(char matchAgainst[], char matchValue[]){
  /*
   *  Same as stringIndex but returns the first location of the rightmost matched value
   *  
   */

  int i, j, k;
  int lastKnownMatch = -1;

  for(i = 0; matchAgainst[i] != '\0'; i++){
    for(j = i, k = 0; matchValue[k] != '\0' && matchAgainst[j] == matchValue[k]; j++, k++)
      ;
    if(k > 0 && matchValue[k] == '\0')
      lastKnownMatch = i;
  }

  return lastKnownMatch;
}

int stringIndex(char matchAgainst[], char matchValue[]){

  int i, j, k;

  for(i = 0; matchAgainst[i] != '\0'; i++){
    for(j = i, k = 0; matchValue[k] != '\0' && matchAgainst[j] == matchValue[k]; j++, k++)
      ;
    if(k > 0 && matchValue[k] == '\0')
      return i;
  }
  return -1;
}

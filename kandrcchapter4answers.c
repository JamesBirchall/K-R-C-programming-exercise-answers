#include "kandrcchapter4answers.h"

int ex4_3(){
  
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
  printf("My String: %s\n", myString2);
  myDouble = stringwithexponenttodouble(myString2);
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

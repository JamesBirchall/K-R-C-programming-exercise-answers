#include "kandrcchapter4answers.h"

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

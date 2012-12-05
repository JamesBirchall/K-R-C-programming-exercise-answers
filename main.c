#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"

int main(){

  char myString[100];
  int i;
  for(i = 0; i < 100; i++)
    myString[i] = '\0';

  itoa(-1235, myString);

  printf("%s\n", myString);

  return 0;
}

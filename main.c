#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"
#include "kandrcchapter4answers.h"

int main(){

  char myString[] = "12345";

  int myInt = 0;
  printf("My String: %s\n", myString);

  myInt = stringtointeger(myString);
  printf("My Int: %d\n", myInt);

  return 0;
}

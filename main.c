#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"
#include "kandrcchapter4answers.h"

int main(){

  char myString[] = "1.1e-4";

  double myDouble = 0.0;
  printf("My String: %s\n", myString);

  //myInt = stringtointeger(myString);
  myDouble = stringwithexponenttodouble(myString);
  printf("My Double: %.4f\n", myDouble);

  return 0;
}

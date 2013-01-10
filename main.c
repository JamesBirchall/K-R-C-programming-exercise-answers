#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"
#include "kandrcchapter4answers.h"

int main(){

  char myString[] = "12344.5678";

  double myDouble = 0.0;
  printf("My String: %s\n", myString);

  myDouble = stringtodouble(myString);
  printf("My Double: %.4f\n", myDouble);

  return 0;
}

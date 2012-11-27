#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"

int main(){

  char mystring[] = "olleH, semaJ";

  printf("%s\n", mystring);

  reverseString(mystring);

  printf("%s\n", mystring);

  return 0;
}

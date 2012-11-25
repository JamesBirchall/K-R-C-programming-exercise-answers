#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"

int main(){

  char string[] = "1234";

  int value = atoi2(string);

  printf("String is:%s, converted makes the integer:%d\n", string, value);

  return 0;
}

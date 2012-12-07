#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"

int main(){
  
  char myString[] = "James Birchall \t\n";

  printf("%s",myString);

  trim(myString);

  printf("%s",myString);
  printf("%s",myString);

  return 0;
}

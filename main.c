#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"

int main(){

  int array[] = {1,2,3,4,5,6,7,8,9,10};

  int toFind = 11;
  int where = -1;

  where = binsearch(toFind, array, 10); 
  if(where >= 0)
    printf("Found at location: %d\n", where);

  if(where == -1)
    printf("Error, number not found!\n");

  return 0;
}

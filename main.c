#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"
#include "kandrcchapter4answers.h"

int main(){

  int values[] = {10,9,8,7,6,5,4,3,2,1,0};

  int i;

  printf("\n");

  for(i = 0; i < 11; i++){
    printf(" %d ", values[i]);
  }

  qsort2(values, 0, 10);

  printf("\n");

  for(i = 0; i < 11; i++){
    printf(" %d ", values[i]);
  }

  return 0;
}

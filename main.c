#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"

int main(){

  int values[] = {10,6,3,7,6,5,4,5,6,2,3,7,8,9};

  int i;

  for(i = 0; i < 14; i++){
    printf("%d ", values[i]);
  }
  printf("\n");

  shellsort(values, 14);


  for(i = 0; i < 14; i++){
    printf("%d ", values[i]);
  }
  printf("\n");

  return 0;
}

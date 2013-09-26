#include <stdio.h>
#include "kandrcchapter1answers.h"
#include "kandrcchapter2answers.h"
#include "kandrcchapter3answers.h"
#include "kandrcchapter4answers.h"
#include "kandrcchapter5answers.h"
#include "kandrcchapter6answers.h"
#include "kandrcchapter7answers.h"
#include "kandrcchapter8answers.h"

int main(int argc, char *argv[]){

  int c;

  while((c = getcharch8()) && (c != tolower('q'))){    
    printf("%c", c);
  }

  return 0;
}

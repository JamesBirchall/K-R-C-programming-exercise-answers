#include "kandrcchapter8answers.h"

void inputtooutput(void){
  char buffer[100];
  int n;

  while((n = read(0, buffer, 100)) > 0){
    write(1, buffer, n);
  }
}

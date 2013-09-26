#include "kandrcchapter8answers.h"

int getcharch8(void){
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

void inputtooutput(void){
  char buffer[100];
  int n;

  while((n = read(0, buffer, 100)) > 0){
    write(1, buffer, n);
  }
}

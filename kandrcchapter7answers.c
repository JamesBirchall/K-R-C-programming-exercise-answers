#include "kandrcchapter7answers.h"

void ex7_2(int argc, char *argv[]){

  int limit = 100;
  
  //program will print non control characters normally
  //control character as hexidecimal values
  //and split text every x characters decided from the start
  char c;

  while((c = getchar()) && c != EOF){
    --limit;
    if(iscntrl(c)){
      printf("0x%X", c);
    } else {
      putchar(c);
    }
    if(limit == 0){
      printf("\n");
      limit = 100;
    }
  }
}

void ex7_1(int argc, char *argv[]){

  printf("Program name = %s\n", argv[0]+2);

  if(strcmp("upper", argv[0] + 2) == 0){
    char c;
    while((c = getchar()) && c != EOF){
      c = toupper(c);
      putchar(c);
    }
  } else if(strcmp("lower", argv[0] + 2) == 0){
    char c;
    while((c = getchar()) && c != EOF){
      c = tolower(c);
      putchar(c);
    }
  } else{
    printf("Usage: upper|lower < document ");
  }

}

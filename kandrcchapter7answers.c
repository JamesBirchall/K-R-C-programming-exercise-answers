#include "kandrcchapter7answers.h"

void part7_3(int argc, char *argv[]){

  minprintfch7("Hello %s, you are too old, by exactly %d years, thats so %f\n", "Jimbo", 101, 20.54);

}

void minprintfch7(char *format, ...){
  va_list argumentpointer;
  char *p, *stringvalue;
  int integervalue;
  double doublevalue;

  va_start(argumentpointer, format);

  for(p = format; *p; p++){
    //if we don't have a modifier just print character to screen
    if( *p != '%'){
      putchar(*p);
      continue;
    }

    switch(*++p){
    case 'd':
      integervalue = va_arg(argumentpointer, int);
      printf("%d", integervalue);
      break;
    case 'f':
      doublevalue = va_arg(argumentpointer, double);
      printf("%f", doublevalue);
      break;
    case 's':
      for(stringvalue = va_arg(argumentpointer, char*); *stringvalue; stringvalue++){
        putchar(*stringvalue);
      }
      break;
    default:
      putchar(*p);
      break;
    }
  }

  va_end(argumentpointer);
}

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

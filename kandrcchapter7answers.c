#include "kandrcchapter7answers.h"

void ex7_6(int argc, char **argv){

  FILE *file1 = NULL, *file2 = NULL;
  char file1line[1000], file2line[1000];

  if(argc < 3){
    printf("\nusage: ./%s file1 file2\n", argv[0]);
    exit(0);
  }

  
  file1 = fopen(argv[1], "r");
  if(file1 == NULL){
    fprintf(stderr, "\nerror: %s can't open %s\n  ", argv[0], argv[1]);
    exit(0);
  }
  file2 = fopen(argv[2], "r");
  if(file2 == NULL){
    fprintf(stderr, "\nerror: %s can't open %s\n  ", argv[0], argv[2]);
    exit(0);
  }

  int linenumber = 0;
  while(
        (fgets(file1line, 1000, file1) != NULL) &&
        (fgets(file2line, 1000, file2) != NULL)){
    if(differentline(file1line, file2line, ++linenumber)){ 
        exit(0);
    }
  }

  fclose(file1);
  fclose(file2);
  
  printf("\nReached the end of files\n");
}

int differentline(char *line1, char *line2, int linenumber){
  if(strcmp(line1, line2) != 0){
    printf("\n%d %s != %s\n", linenumber, line1, line2);
    return 1;
  } else{
    return 0;
  }
}

void ex7_5(){

  char *c;
  char stringvalue[100], buffer[100];
  double value = 0, operand2;
  char e = 0;

  while(scanf("%s%c", stringvalue, &e) == 2){
    if(sscanf(stringvalue, " %lf", &value) == 1){
      pushex7_5(value);
    }
    else if(sscanf(stringvalue, "%s", buffer)){
      for(c = buffer; *c; c++){
        switch (*c){
          case '+':
            pushex7_5(popex7_5() + popex7_5());
            break;
          case '-':
            operand2 = popex7_5();
            pushex7_5(popex7_5() - operand2);
            break;
          case '*':
            pushex7_5(popex7_5() * popex7_5());
            break;
          case '/':
            operand2 = popex7_5();
            if(operand2 != 0.0){
              pushex7_5(popex7_5() / operand2);
            } else{
              printf("\nerror: divide by 0\n");
              break;
            }
          case '\n':
            break;
          default:
            printf("\nerror: unknown command\n");
            break;
        }
      }
      if(e == '\n')
        printf("\n%.8g\n", popex7_5());
    }
  }
}

//variables required for stack
static int stackpointer = 0;
static double stackvalue[100];

void pushex7_5(double value){
  if(stackpointer < 100){
    stackvalue[stackpointer++] = value;
  } else {
    printf("\nerror: stack full, cannot push %f\n", value);
  }
}

double popex7_5(){
  if(stackpointer > 0){
    return stackvalue[--stackpointer];
  } else{
    printf("\nerror: stack is empty\n");
    return 0.0;
  }

}

void ex7_4(){

  int integervalue = 0;

  minscanfch7ex4("%d", &integervalue);
  minprintfch7ex3("Scanned value = %d\n", integervalue);
}

void minscanfch7ex4(char *format, ...){

  //this function will scan in characters based
  //function use = minscanf("%d %u %X", integervalue, unsignedvalue, hexuppervalue);
  //those variables will then contain the appropriate values read in from keyboard or file

  va_list arguments;
  char *p, *stringvalue;
  char *charactervalue;
  char localformat[100];
  int i, *integervalue;
  unsigned *unsignedvalue;
  double *doublevalue;

  i = 0;

  va_start(arguments, format);

  for(p = format; *p; p++){
    if(*p != '%'){
      localformat[i++] = *++p;
      continue;
    }

    localformat[i++] = '%';

    while(*(p+1) && !isalpha(*(p+1))){
      localformat[i++] = *++p;
    }

    localformat[i++] = *(p+1);
    localformat[i] = '\0';

    switch(*++p){
      case 'd':
      case 'i':
        integervalue = va_arg(arguments, int *);
        printf("\nPlease enter an int: ");
        scanf(localformat, integervalue);
        break;
      case 'x':
      case 'X':
      case 'u':
      case 'o':
        unsignedvalue = va_arg(arguments, unsigned *);
        printf("\nPlease enter a unsigned: ");
        scanf(localformat, &unsignedvalue);
        break;
      case 'f':
        doublevalue = va_arg(arguments, double *);
        printf("\nPlease enter a double: ");
        scanf(localformat, &doublevalue);
        break;
      case 's':
        stringvalue = va_arg(arguments, char *);
        printf("\nPlease enter a string: ");
        scanf(localformat, &stringvalue);
        break;
      case 'c':
        charactervalue = va_arg(arguments, char *);
        printf("\nPlease enter a character: ");
        scanf(localformat, &charactervalue);
        break;
      default:
        //scanf("%s", localformat);
        break;
    }
    i = 0;
  }

  va_end(arguments);
}

void ex7_3(){

  minprintfch7ex3("Hello %s, you are too old, by exactly %d years, thats so %f\n", "Jimbo", 101, 20.54);

  minprintfch7ex3("This is a is %u and %i, also %o, %X and %x...%s\n", 127, 123, 123, 123, 123, "James");
}

void minprintfch7ex3(char *format, ...){

  va_list ap;
  char *p, *stringvalue;
  char localformat[100];
  int i, integervalue;
  unsigned unsignedvalue;
  double doublevalue;

  va_start(ap, format);

  for(p = format; *p; p++){
    if(*p != '%'){
      putchar(*p);
      continue;
    }
    i = 0;

    localformat[i++] = '%';
    while( *(p+1) && !isalpha(*(p+1))){
      localformat[i++] = *++p;
    }

    localformat[i++] = *(p+1);
    localformat[i] = '\0';

    switch(*++p){
      case 'd':
      case 'i':
        integervalue = va_arg(ap, int);
        printf(localformat, integervalue);
        break;
      case 'x':
      case 'X':
      case 'u':
      case 'o':
        unsignedvalue = va_arg(ap, unsigned);
        printf(localformat, unsignedvalue);
        break;
      case 'f':
        doublevalue = va_arg(ap, double);
        printf(localformat, doublevalue);
        break;
      case 's':
        stringvalue = va_arg(ap, char*);
        printf(localformat, stringvalue);
        break;
      default:
        printf("%s", localformat); 
        break;
    }
  }

  va_end(ap);

}

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

#include "kandrcchapter5answers.h"

static char buffer[100];
static int bufferfreeposition = 0;

#define MAXLINES 5000
#define MAXSTORE 10000

static char *lineptr[MAXLINES];

int part5_6program_2(){

  int nlines;
  char linestorage[MAXSTORE]; //use for all storage over allocating memory needed

  if((nlines = readlinesch5_2(lineptr, MAXLINES, linestorage)) >= 0){
    printf("Processing lines...\n");
    qsortch5(lineptr, 0, nlines-1);
    printf("Writting lines...\n");
    writelinesch5(lineptr, nlines);
    return 0;
  } else{
    printf("\nerror: input too big to sort\n");
    return 1;
  }
}

int part5_6program(){

  int nlines;

  if((nlines = readlinesch5(lineptr, MAXLINES)) >= 0){
    printf("Processing lines...\n");
    qsortch5(lineptr, 0, nlines-1);
    printf("Writting lines...\n");
    writelinesch5(lineptr, nlines);
    return 0;
  } else{
    printf("\nerror: input too big to sort\n");
    return 1;
  }
}

int getstringlinech5(char charArray[], int limit){
	/*
	 * Read a line of characters into string with limit as max values
	 */
	int character;
	int i;

	for(i = 0; i < limit-1 && (character = getchar()) != EOF && character !='\n'; i++)
		charArray[i] = character;
	if(character == '\n'){
		charArray[i] = character;
		++i;
	}
	charArray[i] = '\0';
	return i;	//returns length of read line
}

#define MAXLENCH5 1000

int readlinesch5_2(char **lineptr, int maxlines, char *linestore){

  int len, nlines;
  char *p, line[MAXLENCH5];

  nlines = 0;
  p = linestore + strlen(linestore);
  
  while((len = getstringlinech5(line, MAXLENCH5)) > 0){
    if(nlines >= maxlines || strlen(linestore) > MAXSTORE){
      printf("\nerror: no space left in fixed memory\n");
      return -1;
    }
    else{
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  }
  
  return nlines;
}

int readlinesch5(char **lineptr, int maxlines){

  int len, nlines;
  char *p, line[MAXLENCH5];

  nlines = 0;
  
  while((len = getstringlinech5(line, MAXLENCH5)) > 0){
    if(nlines >= maxlines || (p = malloc(len)) == NULL){
      printf("\nerror: setting up memory\n");
      return -1;
    }
    else{
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  
  return nlines;
}

void writelinesch5(char **lineptr, int nlines){
  int i;

  for(i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

void qsortch5(char **v, int left, int right){
  int i, last;

  if(left >= right)
    return;

  swapch5(v, left, (left + right) / 2);
  last = left;
  
  for(i = left+1; i <= right; i++){
    if(strcmp(v[i], v[left]) < 0){
      swapch5(v, ++last, i);
    }
  }
  swapch5(v, left, last);
  qsortch5(v, left, last-1);
  qsortch5(v, last+1, right);
}

void swapch5(char **v, int i, int j){
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int ex5_6(){

  char myString[20];

  getlinech5(myString, 20);

  printf("\n%s\n", myString);

  char myString2[] = "1234567";

  int value = atoich5(myString2);

  printf("\n%d\n", value);

  char myString3[20];

  itoach5(value, myString3);

  printf("\n%s\n", myString3);

  char myString4[] = "James";
  char myString5[] = "James";

  value = strindexch5(myString4, myString5);
  printf("\nValue is: %s\n", (value > 0) ? "Yes a match" : "No match");

  char myString6[100];

  int type;

  while((type = getopch5(myString6)) != EOF){
    printf("\nType = %d", type);
    printf("\tString is: %s\n", myString6);
  }

  return 0;
}

int getlinech5(char *s, int lim){

  int c;

  while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
    *s++ = c;
  }
  
  if(c == '\n')
    *s++ = c;

  *s = '\0';

  return 0;
}

int atoich5(char *s){

  int n, sign;

  for( ; isspace(*s); s++);

  sign = (*s == '-') ? -1 : 1;

  if(*s == '+' || *s == '-')
    s++;

  for(n = 0; isdigit(*s); s++)
    n = 10 * n + (*s - '0');

  return sign * n;
}

void itoach5(int number, char *s){
  
  int sign;
  char *t = s; //to retain original pointer as s will get changed

  if((sign = number) < 0)
    number = -number;

  do{
    *s++ = number % 10 + '0';
  } while((number /= 10) > 0);

  if(sign < 0)
    *s++ = '-';
  *s++ = '\0';
  s = t;
  printf("\nBefore swapping: %s\n", s);
  reversech5(s);
}

void reversech5(char *s){
  
  char c;

  char *t = s;

  int j = (strlen(s)-1);

  while(j >= (strlen(t)/2)){

    //set temp value to counter s[0], s[1] etc etc
    c = *s;

    //set s[0], s[1] etc to end[0], end[1] value
    *s = *(t+j); 
    //set end[0], end[1] to temp value effectively swapping the numbers
    *(t+j) = c;

    s++;
    j--;
  }

  s = t;
}

int strindexch5(char *s, char *t){

  //while s is not \0
  int k = 0;

  while(s){
    while(s == t && *t != '\0'){
      k++;
      s++;
      t++;
    }
    if(k > 0 && *t == '\0')
      return 1;
    s++;
  }
 
  return -1;
}

int getopch5(char *s){

  int c;
  char *t = s;

  while((*s = c = getch5()) == ' ' || c == '\t');
  
  s++;

  *s = '\0';

  if(!isdigit(c) && c != '.')
    return c;

  s = t;

  if(isdigit(c))
    while(isdigit(*s++ = c = getch5()));

  if(c == '.')
    while(isdigit(*s++ = c = getch5()));

  *s = '\0';

  if(c != EOF)
    ungetch5(c);

  return 0;
}

int ex5_5(){

  char string1[12];
  char string2[] = "Jimbo";
  char string3[] = "Jimb";
  char string4[] = "Ji";

  strncopych5(string1, string2, 4);
  printf("\n%s\n",string1);

  strncatch5(string1, string2, 3);
  printf("\n%s\n",string1);

  int compared = strncmpch5(string3, string4, 2);
  printf("\n%d\n", compared);


  return 0;
}

int strncopych5(char *s, char *t, int n){

  int counter = 0;

  while(counter++ < n){
    *s++ = *t++;
  }

  *s = '\0';

  return 1;
}

int strncatch5(char *s, char *t, int n){

  int counter = 0;

  while(*s)
    s++;

  while(counter++ < n){
    *s++ = *t++;
  }

  *s = '\0';

  return 0;
}

int strncmpch5(char *s, char *t, int n){

  int counter = 0;

  for( ; *s++ == *t++ && counter++ < n ;){
    if(*s == '\0')
      return 0;
  }

  if(counter >= n)
    return 0;

  return *s - *t;
}

int ex5_4(){

  char string1[] = "James";
  char string2[] = "mes";

  int response = strendch5(string1, string2);

  if(response)
    printf("\nYes\n");
  else
    printf("\nNo\n");
  
  
  return 0;
}

int strendch5(char *s, char *t){

  //returns 1 if the string t occurs at the end of string s

  int status = 0;

  //get length of both strings as we need to retain starting value for later
  int slength = strlen(s);
  int tlength = strlen(t);

  char *q = s+slength;
  char *r = t+tlength;

  //now start from end of s and match against t while not less than start of t
  //if we reach the end return 1, otherwise fall through to end of function
  if(tlength <= slength){
    //start from end point in s and t, compare each element, decrementing by 1 each time
  //while the decreaser is >= 0
  while(tlength >= 0){
      if(*q-- != *r--){
        return 0;
      }
      else
        tlength--;
    }
    if(tlength < 0)
      status = 1;
  }
  
  return status;
}

int ex5_3(){

  char string1[20] = {'H','e','l','l','o',',',' ','\0'};
  char string2[] = "James.";

  printf("\n%s", string1);
  printf("\n%s", string2);

  strcatch5(string1, string2);

  printf("\n%s", string1);
  printf("\n%s", string2);

  return 0;
}

int strcatch5(char *s, char *t){

  //copies string t onto the end of string s using pointers

  int status = 0;

  //get to the part signifying null character \0 in string 1
  while(*s)
    s++;

  //simple append in new string
  while((*s++ = *t++));
    

  return status;
}

int ex5_2(){

  int i;
  float value, numbers[100];

  for(i = 0; i < 100 && (value = getfloatch5(&numbers[i])) != EOF; i++){
    printf("\n number[%d] = %f  %f %s\n",i,numbers[i],value, value != 0 ? "number" : "no number");
  }

  return 0;
}

int getfloatch5(float *pointer){
  float c;
  int sign;
  float decVal = 0.0f;

  while(isspace(c = getch5()));  //skip whitespace

  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    //ungetch5(c); //remove this
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if(c == '+' || c == '-'){
    c = getch5();
    if(!isdigit(c)){
      ungetch5(sign == 1 ? '+' : '-');
      return 0;
    }
  }

  for( *pointer = 0; isdigit(c); c = getch5()){
    *pointer = 10 * *pointer + (c - '0');
  }

  if(c == '.'){
    if(isdigit(c = getch5())){
      int i;
      // its floating point version so process part after and then add to floats
      for(decVal = 0.0, i = 1; isdigit(c); c = getch5(), i++){
          if(i != 0){
            int val = (c - '0');
            decVal += val * pow(0.1,i);
          }
          else{
            decVal = (c - '0')*0.1;  
          }
      }
      *pointer += decVal;
    }
  }

  *pointer *= sign;

  if(c != EOF)
    ungetch5(c);

  return c;
}

int ex5_1(){

  int i, value, numbers[100];

  for(i = 0; i < 100 && (value = getintch5(&numbers[i])) != EOF; i++){
    printf("\n number[%d] = %d  %d %s\n",i,numbers[i],value, value != 0 ? "number" : "no number");
  }

  return 0;
}

int getintch5(int *pointer){
  int c, sign;

  while(isspace(c = getch5()));  //skip whitespace

  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    //ungetch5(c); //remove this
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if(c == '+' || c == '-'){
    c = getch5();
    if(!isdigit(c)){
      ungetch5(sign == 1 ? '+' : '-');
      return 0;
    }
  }

  for( *pointer = 0; isdigit(c); c = getch5()){
    *pointer = 10 * *pointer + (c - '0');
  }

  *pointer *= sign;

  if(c != EOF)
    ungetch5(c);

  return c;
}

void ungetch5(int c){
  if(bufferfreeposition >= 100)
    printf("\nungetch: too many characters\n");
  else{
    //check for EOF pushback and ignore if it is
    if(c != EOF)
      buffer[bufferfreeposition++] = c;
  }
}

int getch5(void){
  return (bufferfreeposition > 0) ? buffer[--bufferfreeposition] : getchar();
}

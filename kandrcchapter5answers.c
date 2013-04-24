#include "kandrcchapter5answers.h"
#include "polishcalc.h"

#define MAXLINESCH5_11 5000
static char *linePointerch5_11[MAXLINESCH5_11];
static int nlines;
static int reversed;

int ex5_14(int argc, char *argv[]){
  
  int numeric = 0;
  reversed = 1;

  if(argc > 1 && strcmp(argv[1], "-n") == 0){
    numeric = 1;
  }

    if((nlines = readlinesch5(linePointerch5_11, MAXLINESCH5_11)) >= 0){
      writelinesch5(linePointerch5_11, nlines);
      printf("\n");
      qsortch5_11((void **) linePointerch5_11, 0, nlines-1, 
           (int (*)(void *, void *))((numeric) ? (int) numcmpch5 : (int) strcmp)); //function passing 
      writelinesch5(linePointerch5_11, nlines);
      printf("\n");
      return 0;
    }
    else{
      printf("\nerror: input too big to sort.\n");
      return 1;
    }

  return 0;
}

int sortBasedOnInput(int argc, char *argv[]){
  
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0){
    numeric = 1;
  }

    if((nlines = readlinesch5(linePointerch5_11, MAXLINESCH5_11)) >= 0){
      writelinesch5(linePointerch5_11, nlines);
      printf("\n");
      if(reversed){
        qsortch5_11((void **) linePointerch5_11, nlines-1, 0, 
             (int (*)(void *, void *))((numeric) ? (int) numcmpch5 : (int) strcmp)); //function passing 
      } else{
        qsortch5_11((void **) linePointerch5_11, 0, nlines-1, 
             (int (*)(void *, void *))((numeric) ? (int) numcmpch5 : (int) strcmp)); //function passing 
      }
      writelinesch5(linePointerch5_11, nlines);
      printf("\n");
      return 0;
    }
    else{
      printf("\nerror: input too big to sort.\n");
      return 1;
    }

  return 0;
}

void swapch5void(void *v[], int i, int j){
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;

}

void qsortch5_11(void *v[], int left, int right, int (*passedCompareFunction)(void *, void *)){
  int i, last;

  writelinesch5(linePointerch5_11, nlines);
  printf("\n");
  if(left >= right){
    return;
  }

  swapch5void(v, left, (left + right) / 2);
  last = left;

  for(i = left+1; i <= right; i++){
    if(reversed){
      if((*passedCompareFunction)(v[i], v[left]) < 0){
       swapch5void(v, i, ++last);
      }
    } else{
      if((*passedCompareFunction)(v[i], v[left]) < 0){
       swapch5void(v, ++last, i);
      }
    }
  }

  swapch5void(v, left, last);
  qsortch5_11(v, left, last-1, passedCompareFunction);
  qsortch5_11(v, last+1, right, passedCompareFunction);
}

int numcmpch5(char *myString1, char *myString2){

  double v1, v2;
  
  if(reversed){
    v2 = atof(myString1);
    v1 = atof(myString2);
  } else{
    v1 = atof(myString1);
    v2 = atof(myString2);
  }

  if(v1 < v2){
    return -1;
  } else if(v1 > v2){
    return 1;
  } else{
    return 0;
  }
}

#define MAXPOINTERSEX5_13 1000
#define MAXINPUTEX5_13 10000

static char actualstrings[MAXINPUTEX5_13];
static char *linepointersex5_13[MAXPOINTERSEX5_13];
static int linesasked = 10; //set as default to 10 lines if user doesn't enter

int ex5_13(int argc, char *argv[]){

  if(argc > 1){
    linesasked = atoi(argv[1]+1);
  }

  *linepointersex5_13 = actualstrings;

  int lines = getlines5_13(actualstrings);

  int linestoprint = lines < linesasked ? lines : linesasked;

  printf("\nPrinting %d lines...\n", linestoprint);

  int i;
  char c;
  for(i = lines; i > 0; i--){
    while((c = *linepointersex5_13[0]++) != '\n'){
      if(i <= linestoprint){
        printf("%c", c);
      }
    }
    if(c == '\n' && i <= linestoprint){
      printf("\n");
    }
  }

  return 0;
}

int getlines5_13(char *buffer){
  int i, count = 0;
  char c;

  for(i = 0; (c = getchar()) != EOF && i < MAXINPUTEX5_13; i++){
    *buffer++ = c;
    if(c == '\n'){
      linepointersex5_13[++count] = buffer;
    }
  }

  return count;
}

int ex5_12(int argc, char *argv[]){

  char myString1[] = "abcde get value after the -bit as a number isolate the values and minus";
  char myString2[100];
  char myString3[] = "a\tb\tc\td\td\t";
  char myString4[100];

  int i;
  for(i = 0; i < 100; i++){
    myString2[i] = '\0';
    myString4[i] = '\0';
  }
  
  //example = programname -e -m +n
  if(argc < 4){
    printf("\nerror: usage is %s -d or -e -m +n (m = starting column, n = n columns)\n", *argv);
    return -1;
  }

  int starting = atoi(argv[2]+1);
  int tabstops = atoi(argv[3]+1);

  if(argv[1][1] == 'd'){
     //run detab
    printf("\n%s\n", myString3);
    detabch5_2(myString4, myString3, tabstops, starting);  
    printf("\n%s\n", myString4);
  } else {
    //run entab
    printf("\n%s\n", myString1);
    entabch5_2(myString4, myString3, tabstops, starting);  
    printf("\n%s\n", myString2);
  }

  return 0;
}
void detabch5_2(char to[], char from[], int tabsize, int starting){


        //this version using starting value to determine where to start detabbing
        printf("\nStarting point = %d\n", starting);

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
                  //while j less than end of file
                  //before starting processing tabs count to starting position by cycling
			if(from[j] == '\t'){
                          if(starting == 0){
				int remainder = tabsize - (newj % tabsize);
				while(remainder > 0){
					to[newj] = ' ';
					remainder--;
					newj++;
				}
				j++;
                          }
                          else{
                            starting--;
			    to[newj] = from[j];
			    j++;
			    newj++;
                          }
			} else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}

void entabch5_2(char to[], char from[], int tabsize, int starting){

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
                        //if characvter is empty
			if(from[j] == ' '){
                                // remainder is tabsize - remainder of new counter and tabsize
				int remainder = tabsize - (newj % tabsize);
				if(remainder > 0){
                                  if(starting == 0){
					to[newj] = '\t';
					newj++;
                                  }else{
                                      starting--;
				      to[newj] = from[j];
				      newj++;
                                  }
				}
				j++;
			}
			else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}

int ex5_11(int argc, char *argv[]){

  char myString1[] = "abcde get value after the -bit as a number isolate the values and minus";
  char myString2[100];
  char myString3[] = "a\tb\tc\td\td\t";
  char myString4[100];

  int i;
  for(i = 0; i < 100; i++){
    myString2[i] = '\0';
    myString4[i] = '\0';
  }

  if(argc < 3){
    printf("\nerror: usage is %s (-e or -d) ENTAB VALUE\n", *argv);
    return -1;
  }

  char enorde[3];
  int entabordetab = 0; // 0 is entab by default

  enorde[2] = '\0';
  enorde[0] = argv[1][0];
  enorde[1] = argv[1][1];

  printf("\nargv 2nd var value: %s\n", enorde);

  if(enorde[1] == 'd'){
    printf("\nYou selected detabbing...\n");
    entabordetab = 1;
  }
  else if(enorde[1] == 'e'){
    printf("\nYou selected entabbing...\n");
  }
  else{
    printf("\nerror, invalid (-argument): usage is %s (-e or -d) ENTAB VALUE\n", *argv);
    return -1;
  }

  if(entabordetab == 0){
    int tabs = atoi(argv[2]);
    printf("\nentabbing by %d\n", tabs);

    printf("\n%s\n", myString1);

    entabch5(myString2, myString1, tabs);
    
    printf("\n%s\n", myString2);

  } else{
    int tabs = atoi(argv[2]);
    printf("\ndetabbing by %d\n", tabs);

    printf("\n%s\n", myString3);

    detabch5(myString4, myString3, tabs);

    printf("\n%s\n", myString4);
  }

  return 0;
}

void detabch5(char to[], char from[], int tabsize){

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
			if(from[j] == '\t'){
				int remainder = tabsize - (newj % tabsize);
				while(remainder > 0){
					to[newj] = ' ';
					remainder--;
					newj++;
				}
				j++;
			} else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}

void entabch5(char to[], char from[], int tabsize){

	int i = 0;
	while(from[i] != '\0'){
		i++;
	}

	if(i > 0){
		int j = 0;
		int newj = 0;

		while(j < i){
                        //if characvter is empty
			if(from[j] == ' '){
                                // remainder is tabsize - remainder of new counter and tabsize
				int remainder = tabsize - (newj % tabsize);
				if(remainder > 0){
					to[newj] = '\t';
					newj++;
				}
				j++;
			}
			else {
				to[newj] = from[j];
				j++;
				newj++;
			}
		}
	}
}

int ex5_10(int argc, char *argv[]){

  double op2;
  int i;

  if(argc < 2){
    printf("\nerror: usage is %s POLISH NOTATION EXPRESSION\n", *argv);
    return -1;
  }

  for(i = 1; i < argc; i++){
    switch (argv[i][0]){
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        push(atof(argv[i]));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2= pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: divide by zero\n");
        break;
      case '\n':
        printf("\n\t%.8g\n", pop());
        break;
      case 'q':
        printf("\n Quitting...\n");
        exit(0);
        break;
      default:
        printf("error: unknown command %s\n", argv[i]);
        break;
    }
  }

  printf("\n\t%.8g\n", pop());
  return 0;
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int ex5_9(){

  int year, month, day;
  year = 2013;
  month = 4;
  day = 14;

  int numberofdays = dayofyear_p(year, month, day);
  if(numberofdays > 0){
    printf("\nThere have been %d days since the start of the year.\n", numberofdays);

    int monthforp = 0;
    int dayforp = 0;

    monthday_p(year, numberofdays, &monthforp, &dayforp);

    printf("\nYou gave me the year %d, so that means its the %d month and %d day.\n", year, monthforp, dayforp);
  }

  return 0;
}

int dayofyear_p(int year, int month, int day){
  
  int i, leap;
  char *charpointer;

  if(year < 1800 || month < 1 || month > 12 || day < 1 || day > 31){
    printf("\nerror: invalid input, check year > 1800, month is valid and day not greater than 31\n");
    return -1;
  }
  
  leap = year%4 == 0 && year%100 != 0 && year%4 == 0;

  //now check for day again but more specific this time e.g days expected of the month!
  if(day > daytab[leap][month]){
    printf("\nerror: invalid day, please check you have the right number corresponding to the month\n");
    return -1;
  }

  charpointer = &daytab[leap][1]; //point to correct row dpenedent on leapyear or not

  for(i = 1; i < month; i++){
    day += *charpointer++;
  }
   
  return day;
}

int monthday_p(int year, int yearday, int *pmonth, int *pday){

  int i, leap;
  char *charpointer;

  if(year < 1800 && yearday < 0){
    printf("\nerror: invalid input, check year > 1800, and yeardays is greater than 0\n");
    return -1;
  }

  leap = year%4 == 0 && year%100 != 0 && year%4 == 0;

  if((leap && yearday > 366) || (!leap && yearday > 365)){
    printf("\nerror: check you have the right number of days in your year!\n");
    return -1;
  }

  /*for(i = 1; yearday > daytab[leap][i]; i++){
    yearday-= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;*/

  charpointer = &daytab[leap][1]; //point to correct row dependent on leap year or not

  //need to extract the month and day from the yearday variable, we know the year
  //go through each month and knock off x days to end up with actual days left and
  //each time loop through get a count of the months made up
  for(i = 1; yearday > *charpointer; i++){
    yearday -= *charpointer++;
  }

  *pmonth = i;
  *pday = yearday;

  return 0;
}

int ex5_8(){

  int year, month, day;
  year = 2013;
  month = 4;
  day = 14;

  int numberofdays = dayofyear(year, month, day);
  if(numberofdays > 0){
    printf("\nThere have been %d days since the start of the year.\n", numberofdays);

    int monthforp = 0;
    int dayforp = 0;

    monthday(year, numberofdays, &monthforp, &dayforp);

    printf("\nYou gave me the year %d, so that means its the %d month and %d day.\n", year, monthforp, dayforp);
  }

  return 0;
}

int dayofyear(int year, int month, int day){

  int i, leap;

  if(year < 1800 || month < 1 || month > 12 || day < 1 || day > 31){
    printf("\nerror: invalid input, check year > 1800, month is valid and day not greater than 31\n");
    return -1;
  }
  
  leap = year%4 == 0 && year%100 != 0 && year%4 == 0;

  //now check for day again but more specific this time e.g days expected of the month!
  if(day > daytab[leap][month]){
    printf("\nerror: invalid day, please check you have the right number corresponding to the month\n");
    return -1;
  }

  for(i = 1; i < month; i++){
    day += daytab[leap][i];
  }
  
  return day;
}

int monthday(int year, int yearday, int *pmonth, int *pday){
  int i, leap;

  if(year < 1800 && yearday < 0){
    printf("\nerror: invalid input, check year > 1800, and yeardays is greater than 0\n");
    return -1;
  }

  leap = year%4 == 0 && year%100 != 0 && year%4 == 0;

  if((leap && yearday > 366) || (!leap && yearday > 365)){
    printf("\nerror: check you have the right number of days in your year!\n");
    return -1;
  }

  for(i = 1; yearday > daytab[leap][i]; i++){
    yearday-= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;

  return 0;
}

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
    printf("%s\t", lineptr[i]);
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

void swapch5ints(int **v, int i, int j){
  int *temp;

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

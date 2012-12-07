#include "kandrcchapter3answers.h"

int trim(char s[]){
  int n;

  for(n = strlen(s)-1; n >= 0; n--)
    if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
    s[n+1] = '\0';
  return n;
}

void ex3_6(){
  int myNumber = INT_MIN;
  char myString[100] = "";

  int i;
  for(i = 0; i < 100; i++){
    myString[i] = '\0';
  }

  printf("Integer: %d\n", myNumber);

  itoafixedversionminwidth(myNumber, myString, 50);

  printf("Converted to String: %s\n", myString);
}

void itoafixedversionminwidth(int number, char newString[], int minwidth){

  int i, sign;

  if((sign = number) < 0)
    number = -number;

  i = 0;
  do{
    int absValue = abs(number%10)+'0';
    printf("...Processing absolute value of %d %% 10 + 0 = %c\n",number, absValue);
    if(minwidth)
      --minwidth;
    newString[i++] = abs(number % 10) + '0'; //fix to get correct character
    printf("Divide by 10...original value: %d\n", number/10);
  } while(number /= 10);  // fixed part as we will end up with negative in two's complement

  if(sign < 0)
    newString[i++] = '-', --minwidth;

  if(minwidth)
    while(minwidth--)
      newString[i++] = ' ';
  newString[i++] = '\0';
  reverseString(newString);
}

void ex3_5(){

  int myNumber = INT_MIN;
  char myString[100] = "";

  int i;
  for(i = 0; i < 100; i++){
    myString[i] = '\0';
  }

  printf("Integer: %d\n", myNumber);

  itobase(myNumber, myString, 8);

  printf("Converted to String: %s\n", myString);
}

void itobase(int number, char newString[], int numberBase){
  /*
   *  Similar to itoafixedversion but allows any bases to be printed to the string
   *  Currently only allows Binary, Octal, Hexidecimal and if no limit is given defaults to
   *  base 10.
   */

  int i, sign;
  char base16[] = "0123456789ABCDEF";
  char base2[] = "01";
  char base8[] = "01234567";

  if((sign = number) < 0)
    number = -number;

  i = 0;

  do{
    int absValue = abs(number%numberBase)+'0';
    printf("...Processing absolute value of %d %% 10 + 0 = %c\n",number, absValue);
    if(numberBase == 16)
    {
      newString[i++] = base16[abs(number % numberBase)];
      printf("Divide by 16...original value: %d\n", number/numberBase);
    } else if(numberBase == 2){
      newString[i++] = base2[abs(number % numberBase)];
      printf("Divide by 2...original value: %d\n", number/numberBase);
    } else if(numberBase == 8){
      newString[i++] = base8[abs(number % numberBase)];
      printf("Divide by 8...original value: %d\n", number/numberBase);
    } else {
      newString[i++] = abs(number % numberBase) + '0'; //fix to get correct character
      printf("Divide by 10...original value: %d\n", number/10);
    }
  } while(number /= numberBase);  // fixed part as we will end up with negative in two's complement

  if(sign < 0)
    newString[i++] = '-';
  newString[i++] = '\0';
  reverseString(newString);

}

void ex3_4(){
  int myNumber = INT_MIN;
  char myString[100] = "";

  int i;
  for(i = 0; i < 100; i++){
    myString[i] = '\0';
  }

  printf("Integer: %d\n", myNumber);

  itoafixedversion(myNumber, myString);

  printf("Converted to String: %s\n", myString);
}

void itoafixedversion(int number, char newString[]){
  int i, sign;

  if((sign = number) < 0)
    number = -number;

  i = 0;
  do{
    int absValue = abs(number%10)+'0';
    printf("...Processing absolute value of %d %% 10 + 0 = %c\n",number, absValue);
    newString[i++] = abs(number % 10) + '0'; //fix to get correct character
    printf("Divide by 10...original value: %d\n", number/10);
  } while(number /= 10);  // fixed part as we will end up with negative in two's complement

  if(sign < 0)
    newString[i++] = '-';
  newString[i++] = '\0';
  reverseString(newString);
}

void itoa(int number, char newString[]){
  int i, sign;

  if((sign = number) < 0)
    number = -number;

  i = 0;
  do{
    newString[i++] = number % 10 + '0';
  } while((number /= 10) > 0);

  if(sign < 0)
    newString[i++] = '-';
  newString[i++] = '\0';
  reverseString(newString);
}

void ex3_2(){
  char myString[] = "James\tis\nCool\\beyond\"awesome\'just right";
  char myString2[100];
  char myString3[100];

  int i;
  for(i = 0; i < 100; i++){
    myString2[i] = '\0';
    myString3[i] = '\0';
  }

  printf("%s\n", myString);
  
  escape(myString2, myString);
  
  printf("%s\n", myString2);

  unescape(myString3, myString2);

  printf("%s\n", myString3);
}

void escape(char s[], char t[]){
  /*
   *  Converts strgins containing escape characters into
   *  a string which prints out \escapechar.  Place this
   *  new string in s, use a switch statement.
   */

  int i = 0;
  int j = 0;

  while(t[i]){

    switch(t[i]){
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        i++;
        break;
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        i++;
        break;
      case '\"':
        s[j++] = '\\';
        s[j++] = '\"';
        i++;
        break;
      case '\a':
        s[j++] = '\\';
        s[j++] = 'a';
        i++;
        break;
      case '\b':
        s[j++] = '\\';
        s[j++] = 'b';
        i++;
        break;
      case '\f':
        s[j++] = '\\';
        s[j++] = 'f';
        i++;
        break;
      case '\r':
        s[j++] = '\\';
        s[j++] = 'r';
        i++;
        break;
      case '\v':
        s[j++] = '\\';
        s[j++] = 'v';
        i++;
        break;
      case '\'':
        s[j++] = '\\';
        s[j++] = '\'';
        i++;
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        i++;
        break;
      case '\?':
        s[j++] = '\\';
        s[j++] = '\?';
        i++;
        break;
      default:
        s[j++] = t[i++];
        break;

    }
  }
}

void unescape(char s[], char t[]){
  /*
   *  Opposite function to escape, returns string to original form into s
   */

  int i = 0;
  int j = 0;

  while(t[i]){
    if(t[i] != '\\'){
      s[j++] = t[i++];
    }
    else{
      switch(t[i+1]){
        case 't':
          s[j++] = '\t';
          i+=2;
          break;
        case 'n':
          s[j++] = '\n';
          i+=2;
          break;
        case 'a':
          s[j++] = '\a';
          i+=2;
          break;
        case 'b':
          s[j++] = '\b';
          i+=2;
          break;
        case 'f':
          s[j++] = '\f';
          i+=2;
          break;
        case 'v':
          s[j++] = '\v';
          i+=2;
          break;
        default:
          s[j++] = t[i+1];
          i+=2;
          break;
      }
      //s[j++] = t[i+1];
      //i+=2;
    }
      
      //switch(t[i]){
      //  case '\\'
      //}  
  }
}

void ex3_3(){
  char myString[] = "a-z";
  char myString2[] = "A-z";
  char myString3[] = "a-b-c-";
  char myString4[] = "a-z0-9"; //add 0-9 after
  char myString5[] = "-a-zA-F4-9c";

  char myString6[100];
  char myString7[100];
  char myString8[100];
  char myString9[100];
  char myString10[100];

  int i;
  for(i = 0; i < 100; i++){
    myString6[i] = '\0';
    myString7[i] = '\0';
    myString8[i] = '\0';
    myString9[i] = '\0';
    myString10[i] = '\0';
  }

  printf("String1:%s\n", myString);
  printf("String2:%s\n", myString2);
  printf("String3:%s\n", myString3);
  printf("String4:%s\n", myString4);
  printf("String5:%s\n", myString5);

  expandString(myString, myString6);
  expandString(myString2, myString7);
  expandString(myString3, myString8);
  expandString(myString4, myString9);
  expandString(myString5, myString10);

  printf("String6:%s\n", myString6);
  printf("String7:%s\n", myString7);
  printf("String8:%s\n", myString8);
  printf("String9:%s\n", myString9);
  printf("String10:%s\n", myString10);
}

void expandString(char s1[], char s2[]){
  /*
   *  Expands shorthand notation like a-z in s1 into the complete 
   *  list of characters e.g abcdefghijklmnopqrstuvwxy
   *  Allows for any case and digits, a-b-c, a-z0-9 and -a-z
   *  taking leading - literally
   */
  
  //tasks:
  //  determine starting value from s1
  //  if leading values, take them litterally (copy directly across to s2
  //  determine ending value - loop to end of string looking for repeating end
  //  characters e.g a-n-p
  //  set look starting at starting value
  //  place characters into s2 after literals until hit end value
  //  rely on the calling program to allocate enough space for s2

  //  start processing, if a leading - is found copy it

  int i = 0;
  int j = 0;
  int min = 0;
  int max = 0;

  while(s1[i]){
    /*if((s1[i] == '-' && min == 0) || ((s1[i] == '-') && (s1[i+1] == '\0') && (max != 0))){
      
      if((min != 0 && max == 0) && s[i] == '-' ){
        max = min;
        continue;
      }      
      
      s2[j++] = s1[i++];
      continue;
    }*/

    if(s1[i] == '-' && min == 0){
      if(i == 0){
        s2[j++] = s1[i++];
        continue;
      }
    }

    if(s1[i] == '-' && s1[i+1] == '\0'){
      if(max == 0){
        max = min;
        s2[j++] = max;
        continue;
      } else{
        s2[j++] = s1[i++];
        continue;
      }
    }


    //get min & max value!
    if(isalnum(s1[i])){
      if(min == 0){
        min = s1[i++];
      }
      else{
        max = s1[i++];
      }
    }else{
      if(s1[i] == '-'){
        i++;
      } else{
        printf("Error value not valid range: %s\n", s1);
        exit(0);
      }
    }

    //printf("Min: %c, Max: %c\n", min, max);
    if((min != 0 && max != 0) && (min <= max)){
      while(min != max+1){
        //printf("%c ", min);
        if(isalnum(min))
          s2[j++] = min++;
        else
          min++;
      }

      min = 0;
      max = 0;
    }
  }
}

void reverseString(char s[]){
  int c, i, j;

  for(i = 0, j = strlen(s)-1; i < j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void shellsort(int values[], int count){

  int gap, i, j, temp;

  for(gap = count/2; gap > 0; gap /= 2){
    for(i = gap; i < count; i++){
      for(j = i-gap; j >= 0 && values[j] > values[j+gap]; j -= gap){
        temp = values[j];
        values[j] = values[j+gap];
        values[j+gap] = temp;
      }
    }
  }
}

int atoi2(char string[]){
  int i, n, sign;

  for(i = 0; isspace(string[i]); i++)
    ; //skip whitespaces
  sign = (string[i] == '-') ? -1 : 1;

  if(string[i] == '+' || string[i] == '-')  //skip sign
    i++;

  for(n = 0; isdigit(string[i]); i++)
    n = 10 * n + (string[i] - '0');
  
  return sign * n;
}


void ex3_1(){
  int array[] = {1,2,3,4,5,6,7,8,9,10};

  int toFind = 1;
  int where = -1;

  where = newbinsearch(toFind, array, 10);
  if(where < 0)
    printf("Sorry number not found\n");
  else
    printf("Number %d found at location array[%d]\n", toFind, where);
}


int newbinsearch(int tofind, int values[], int max){
  /*
   *  Attempt to provide bin search below but with only one test made inside the loop
   */
  int low, mid, high;

  low = 0;
  high = max-1;

  /*
   *  inside loop will divide an conquer, 
   */
  mid = (low+high)/2;

  while(low+1 < high){
    printf("Low:%d Mid:%d High:%d\n", low, mid, high);
    if(tofind <= mid)
      high = mid;
    else
      low = mid;

    mid = (low+high)/2;
  }

  if(tofind == values[mid])
    return mid;
  else if(tofind == values[high])
    return high;
  else
    return -1;
}

int binsearch(int tofind, int values[], int max){
  int low, mid, high;

  low = 0;
  high = max-1;

  while(low <= high){
    mid = (low+high) / 2; // get mid point

    if(tofind < values[mid])
      high = mid - 1;
    else if(tofind > values[mid])
      low = mid + 1;
    else
      return mid;      
  }

  return -1;
}

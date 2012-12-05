#include "kandrcchapter3answers.h"


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

  int i;
  for(i = 0; s1[i] != '\0'; i++){
    printf("%c", s1[i]); 
  }

  printf("\n");

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

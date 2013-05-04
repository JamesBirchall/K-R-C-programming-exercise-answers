#include "kandrcchapter6answers.h"
#include "kandrcchapter5answers.h"

struct charkey keytab[] = {
  {"auto", 0},
  {"const", 0},
  {"void", 0}
};

#define NKEYS (sizeof keytab / sizeof(struct charkey))

int getwordch6(char *word, int limit){
  int c;
  char *w = word;

  while(isspace(c = getch5()));

  if(c != EOF)
    *w++ = c;

  if(!isalpha(c)){
    *w = '\0';
    return c;
  }
  for(; --limit > 0; w++){
    if(!isalpha(*w = getch5())){
      ungetch5(*w);
      break;
    }
  }
  *w = '\0';

  return word[0];
}

int binsearchch6(char *word, struct charkey *tab, int n){

  int cond;
  int low, high, mid;

  low = 0; high = n-1;

  while(low <= high){
    mid = (low+high)/2;
    if((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}

int ch6_sec4(){
  int n;
  char word[100];

  while(getwordch6(word, 100) != EOF){
    if(isalpha(word[0])){
      if((n = binsearchch6(word, keytab, NKEYS)) >= 0){
        keytab[n].count++;
      }
    }
  }

  for(n = 0; n < NKEYS; n++)
    if(keytab[n].count > 0)
      printf("\n%4d %s\n", keytab[n].count, keytab[n].word);

  return 0;
}

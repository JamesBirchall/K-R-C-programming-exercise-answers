#include "kandrcchapter6answers.h"
#include "kandrcchapter5answers.h"

struct charkey keytab[] = {
  {"#define", 0},
  {"_something", 0},
  {"auto", 0},
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"const", 0},
  {"continue", 0},
  {"default", 0},
  {"do", 0},
  {"double", 0},
  {"else", 0},
  {"enum", 0},
  {"extern", 0},
  {"float", 0},
  {"for", 0},
  {"goto", 0},
  {"if", 0},
  {"int", 0},
  {"long", 0},
  {"register", 0},
  {"return", 0},
  {"short", 0},
  {"signed", 0},
  {"sizeof", 0},
  {"static", 0},
  {"struct", 0},
  {"switch", 0},
  {"typedef", 0},
  {"union", 0},
  {"unsigned", 0},
  {"void", 0},
  {"volatile", 0},
  {"while", 0}
};

#define NKEYS (sizeof keytab / sizeof(struct charkey))


int ex6_1(){
  //handle underscores, string constants, comments and preprocessor control lines
  //_underscorestring_
  //"string constant"
  ////comment string
  //#pre processor stuff

  int n;
  char word[100];

  while(getwordch6ex1(word, 100) != 0){
      if((n = binsearchch6(word, keytab, NKEYS)) >= 0){
        keytab[n].count++;
        printf("\nMatch found...\n");
      }
  }

  for(n = 0; n < NKEYS; n++)
    if(keytab[n].count > 0)
      printf("\n%4d %s\n", keytab[n].count, keytab[n].word);

  return 0;
}

int getwordch6ex1(char *word, int limit){
  int c, d;
  char *w = word;

  while(isspace(c = getch5()));

  if(c != EOF)
    *w++ = c;

  //if its a character or an underscore or a pre processor directive
  if(isalpha(c) || c == '_' || c == '#'){
    for(; limit > 0; w++){
      if(!isalnum(*w = getch5())){
        ungetch5(*w);
        break;
      }
    }
  } else if( c == '\'' || c == '"'){
    for(; --limit > 0; w++)
      if((*w = getch5()) == '\\'){
        *++w = getch5();
      } else if( *w == c){
        w++;
        break;
      } else if (*w == EOF)
        break;
  } else if(c == '/'){
    if((d = getch5()) == '*')
      c = commentch6();
    else
      ungetch5(d);
  }
      
  *w = '\0';

  printf("\nReturning %d\n", word[0]);

  return word[0];
}

int commentch6(void){

  int c;

  while((c = getch5()) != EOF){
    if(c == '*'){
      if((c = getch5()) == '/')
        break;
      else
        ungetch5(c);
    }
  }

  return c;
}

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

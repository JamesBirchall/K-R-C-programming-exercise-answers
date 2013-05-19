#include "kandrcchapter6answers.h"
#include "kandrcchapter5answers.h"

static struct nlist *hashtab[HASHSIZE];
int ch6_6(){

  installch6("James", "Person");
  installch6("Somewhere", "Else");
  installch6("Yes", "No");

  int counter = 0;
  while(counter < HASHSIZE){
    if(hashtab[counter] != NULL){
      
      printf("\n%s is now %s, held at %d\n", hashtab[counter]->name, hashtab[counter]->defn, counter);
    }
    counter++;
  }

  return 0;
}

unsigned int hashch6(char *s){
  unsigned int hashval;

  for(hashval = 0; *s != '\0'; s++)
    hashval = *s +31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist *lookupch6(char *s){
  struct nlist *np;

  for(np = hashtab[hashch6(s)]; np != NULL; np = np->next)
    if(!strcmp(s, np->name))
      return np;
    return NULL;
}

struct nlist *installch6(char *name, char *defn){
  struct nlist *np;

  unsigned int hashval;

  if((np = lookupch6(name)) == NULL){
    //not found in lookup
    np = (struct nlist *) malloc(sizeof(*np));
    if(np == NULL || ((np->name = stringduplicate(name))) == NULL)
      return NULL;
    hashval = hashch6(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else{
    free((void *) np->defn);  //free previous definition
  }

  if(((np->defn = stringduplicate(defn))) == NULL)
    return NULL;

  return np;
}


struct treenode nodelist[1000];  //set max nodes in list to 1000
int nodecount = 0;  //used to hold how many nodelist nodes there are

int ex6_4(int argc, char *argv[]){

  struct treenode *root;
  char word[100];
  int linenumber = 1;

  root = NULL;

  while(getwordch6(word, 100) != EOF){
    int len = strlen(word);
    int foundnewline = 0;

    if(word[len-1] == '\n'){
      foundnewline = 1;
      word[len-1] = '\0';
    }

    if(isalpha(word[0]) && !checkfornoisewords(word)){
      root = addtree2(root, word, linenumber);
    }

    if(foundnewline == 1){
      linenumber++;
      foundnewline = 0;
    }
  }

  int i;
  //store nodes into the list above
  storenodes(root);
  printf("\n::Before sort::");
  for (i = 0; i < nodecount; i++){
    printf("\nCount: %d\tWord: %s\n", nodelist[i].count, nodelist[i].word);
  }
  sortnodelist();
  printf("\n::After sort::");
  for (i = 0; i < nodecount; i++){
    printf("\nCount: %d\tWord: %s\n", nodelist[i].count, nodelist[i].word);
  }

  return 0;
}

void storenodes(struct treenode *node){
  //loop through in same way as print and store each node and increment counter


  if(node != NULL){
    storenodes(node->left);
    //do work
    if(nodecount < 1000){
      nodelist[nodecount++] = *node;
    }
    storenodes(node->right);
  }
  
}

void sortnodelist(void){
  //sort nodelist by count value
  qsort((void*) &nodelist[0], nodecount, sizeof(nodelist[0]), (__compar_fn_t) comparenodeex6_4);
}

int comparenodeex6_4(const void *c, const void *d){

  int firstNumber, secondNumber = 0;

  firstNumber = ((struct treenode *)c)->count;
  secondNumber = ((struct treenode *)d)->count;

  if(firstNumber == secondNumber)
    return 0;
  else
    return (firstNumber < secondNumber) ? 1 : -1;

}

int checkfornoisewords(char *s){
  //check for noise words and return 1 if match is made, 0 if not

  char *noisewords[] = {
  "and",
  "the",
  "a",
  "that"
  };

  int count = 0;

  while(count < 4){
  
    if(strcmp(s, noisewords[count]) == 0)
      return 1;

    count++;
  }
  
  return 0;
}

int ex6_3(int argc, char *argv[]){

  struct treenode *root;
  char word[100];
  int linenumber = 1;

  root = NULL;

  while(getwordch6(word, 100) != EOF){
    //in here we now need to deal with words returned with a \n in them, basically setting the \n to \0
    int len = strlen(word);
    int foundnewline = 0;

    if(word[len-1] == '\n'){
      foundnewline = 1;
      word[len-1] = '\0';
    }

    if(isalpha(word[0]) && !checkfornoisewords(word)){
      root = addtree2(root, word, linenumber);
    }

    if(foundnewline == 1){
      linenumber++;
      foundnewline = 0;
    }
  }

  treeprint2(root);

  return 0;
}

int ch6_5(){

  struct treenode *root;

  char word[100];

  root = NULL;

  while(getwordch6(word, 100) != EOF){
    if(isalpha(word[0]))
      root = addtree(root, word);
  }

  treeprint(root);

  return 0;
}

struct treenode *addtree2(struct treenode *node, char *word, int linenumber){

  int condition;

  if(node == NULL){
    //new word arrived so setup new struct and allocate memory
    node = talloc();
    node->word = stringduplicate(word);  //so we use strdup to get memory for string
    //had we not bothered and pointed to the string parameter (word), the memory
    //will be cleaned up after the function call allow the memory to be re-used
    //as it is from the stack
    //alloc gets heap which is there till we remove it
    node->count = 1;
    node->left = node->right = NULL;  //set pointers left & right to NULL
    node->startinglinelist = lalloc();
    node->startinglinelist->linenumbervalue = linenumber;
    node->startinglinelist->next = NULL;  
  } else if((condition = strcmp(word, node->word)) == 0){
    node->count++;
    linenode(node, linenumber);
  }else if(condition < 0)
    node->left = addtree2(node->left, word, linenumber);
  else
    node->right = addtree2(node->right, word, linenumber);

  return node;
}

void linenode(struct treenode *node, int linenumber){
  struct lines *tempnode;

  tempnode = node->startinglinelist;
  //traverse linked list
  while(tempnode->next != NULL && tempnode->linenumbervalue != linenumber){
    tempnode = tempnode->next;
  }

  if(tempnode->linenumbervalue != linenumber){
    tempnode->next = lalloc();
    tempnode->next->linenumbervalue = linenumber;
    tempnode->next->next = NULL;
  }
}

struct lines *lalloc(void){
  return (struct lines *) malloc(sizeof(struct lines));
}

struct treenode *addtree(struct treenode *node, char *word){

  int condition;

  if(node == NULL){
    //new word arrived so setup new struct and allocate memory
    node = talloc();
    node->word = stringduplicate(word);  //so we use strdup to get memory for string
    //had we not bothered and pointed to the string parameter (word), the memory
    //will be cleaned up after the function call allow the memory to be re-used
    //as it is from the stack
    //alloc gets heap which is there till we remove it
    node->count = 1;
    node->left = node->right = NULL;  //set pointers left & right to NULL

  } else if((condition = strcmp(word, node->word)) == 0)
    node->count++;
  else if(condition < 0)
    node->left = addtree(node->left, word);
  else
    node->right = addtree(node->right, word);

  return node;
}

void treeprint2(struct treenode *node){

  struct lines *temp;
  
  if(node != NULL){
    treeprint2(node->left);
    printf("Count:%4d::\tWord: %s ::\tLines: ", node->count, node->word);
    for(temp = node->startinglinelist; temp != NULL; temp = temp->next){
      printf("%4d ", temp->linenumbervalue);
    }
    printf("\n");
    treeprint2(node->right);
  }
}

void treeprint(struct treenode *node){
  
  if(node != NULL){
    treeprint(node->left);
    printf("%4d %s\n", node->count, node->word);
    treeprint(node->right);
  }
}

struct treenode *talloc(void){
  //get memory size of 1 treenode and return pointer as
  //a treenode pointer
  return (struct treenode *) malloc(sizeof(struct treenode));
}

char *stringduplicate(char *s){
  char *p;

  //get memory for string duplicate +1 for null terminated
  //as strlen doesn't include that but we need it to 
  //treat the copied string as a string :-)
  p = (char*) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);

  return p;
}

struct charkey keytab[] = {
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

struct charkey2 keytab2[] = {
  {"auto", 0, 0},
  {"break", 0, 0},
  {"case", 0, 0},
  {"char", 0, 0},
  {"const", 0, 0},
  {"continue", 0, 0},
  {"default", 0, 0},
  {"do", 0, 0},
  {"double", 0, 0},
  {"else", 0, 0},
  {"enum", 0, 0},
  {"extern", 0, 0},
  {"float", 0, 0},
  {"for", 0, 0},
  {"goto", 0, 0},
  {"if", 0, 0},
  {"int", 0, 0},
  {"long", 0, 0},
  {"register", 0, 0},
  {"return", 0, 0},
  {"short", 0, 0},
  {"signed", 0, 0},
  {"sizeof", 0, 0},
  {"static", 0, 0},
  {"struct", 0, 0},
  {"switch", 0, 0},
  {"typedef", 0, 0},
  {"union", 0, 0},
  {"unsigned", 0, 0},
  {"void", 0, 0},
  {"volatile", 0, 0},
  {"while", 0, 0}
};

#define NKEYS (sizeof keytab / sizeof(struct charkey))
#define NKEYS2 (sizeof keytab2 / sizeof(struct charkey2))

int ex6_2(int argc, char *argv[]){

  char word[100];
  struct charkey2 *p;
  char tomatch[100];
  int tomatchlength = 0;

  //get string to match in words
  if(argc > 1){
    int i = 0;
    while(isalnum(argv[1][i])){
      tomatch[i] = argv[1][i];
      i++;
    }
    tomatch[i] = '\0';
    tomatchlength = i;
  }

  printf("\n%s\n", tomatch);

  while(getwordch6(word, 100) != EOF){
    if(isalpha(word[0]))
      if((p = binsearchch6pointer2(word, keytab2, NKEYS2)) != NULL){
        p->count++;
        if(strncmp(p->word, tomatch,tomatchlength) == 0)
          p->matched = 1;
      }
  }

  printf("\n");

  for(p = keytab2; p < keytab2 + NKEYS2; p++)
    printf("Word: %s\t\t has been used:%4d time%s and %s match input string\n", p->word, p->count, (p->count == 1) ? "" : "s", (p->matched) ? "does" : "does not" );

  return 0;
}

int ch6_sec4_2(){
  //pointer version of ch6_sec4_2()

  char word[100];
  struct charkey *p;

  while(getwordch6(word, 100) != EOF){
    if(isalpha(word[0]))
      if((p = binsearchch6pointer(word, keytab, NKEYS)) != NULL)
        p->count++;
  }

  printf("\n");

  for(p = keytab; p < keytab + NKEYS; p++)
    printf("Word: %s\t\t has been used:%4d time%s", p->word, p->count, (p->count == 1) ? "\n" : "s\n");

  return 0;
}

struct charkey2 *binsearchch6pointer2(char *word, struct charkey2 *tab, int n){

  int cond;
  struct charkey2 *low = &tab[0];
  struct charkey2 *high = &tab[n];
  struct charkey2 *mid;

  while(low < high){
    mid = low + (high - low) / 2;
    if((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }

  return NULL;
}

struct charkey *binsearchch6pointer(char *word, struct charkey *tab, int n){

  int cond;
  struct charkey *low = &tab[0];
  struct charkey *high = &tab[n];
  struct charkey *mid;

  while(low < high){
    mid = low + (high - low) / 2;
    if((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }

  return NULL;
}

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

  if(!isalpha(c) && c != '\n'){
    *w = '\0';
    return c;
  }

  for(; --limit > 0; w++){
    //need to amend this to add in '\n'
    *w = getch5();
    if(*w == '\n'){
      w++;
      break;
    }
    if(!isalpha(*w)){
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

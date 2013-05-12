#if !defined(_KANDREX_H6)
#define _KANDREX_H6

struct charkey{
  char *word;
  int count;
}; 

struct charkey2{
  char *word;
  int count;
  int matched;
};

//used for 1 way list to keep numbers
struct lines{
  struct lines *next;
  int linenumbervalue;
};

//extended to add pointer to starting line number
struct treenode{
  char *word;
  int count;
  struct treenode *left;
  struct treenode *right;
  struct lines *startinglinelist;
};

//#define NKEYS (sizeof keytabs / sizeof (struct charkey))
//#define NKEYS2 (sizeof keytabs2 / sizeof (struct charkey2))

struct nlist{
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

unsigned int hashch6(char *);
struct nlist *lookupch6(char *);
struct nlist *installch6(char *, char *);

int comparenodeex6_4(const void *, const void *);
int ch6_5();
void storenodes(struct treenode *);
void sortnodelist(void);
struct treenode *addtree2(struct treenode *, char *, int linenumber);
struct treenode *addtree(struct treenode *, char *);
void treeprint(struct treenode *);
void treeprint2(struct treenode *);
struct treenode *talloc(void);
struct lines *lalloc(void);
void linenode(struct treenode *, int);
char *stringduplicate(char *);
int checkfornoisewords(char *);
int getwordch6(char *, int);
int binsearchch6(char *, struct charkey *, int);
struct charkey *binsearchch6pointer(char *, struct charkey *, int);
struct charkey2 *binsearchch6pointer2(char *, struct charkey2 *, int);
int ch6_sec4();
int ch6_sec4_2();
int ex6_4(int, char **);
int ex6_3(int, char **);
int ex6_2(int, char **);
int ex6_1();
int getwordch6ex1(char *, int);
int commentch6(void);



#endif

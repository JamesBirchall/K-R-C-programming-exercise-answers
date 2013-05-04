#if !defined(_KANDREX_H6)
#define _KANDREX_H6

struct charkey{
  char *word;
  int count;
}; 

//#define NKEYS (sizeof keytabs / sizeof (struct charkey))

int getwordch6(char *, int);
int binsearchch6(char *, struct charkey *, int);
int ch6_sec4();

#endif

#include <stdio.h>

int main()
{
  int c, i, nwhite, nother, ndigit[10];

  nwhite=nother=0;
  for(int i=0; i<10; i++)ndigit[i]=0;

  while((c=getchar())!='\n')
  {
    switch(c)
    {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        ndigit[c-'0']++; break;

      case '\t': case ' ':
        nwhite++; break;

      default: nother++; break;
    }
  }

  for(int i=0; i<10; i++)printf("%d - %d\n", i, ndigit[i]);
  printf("whitespace - %d\n", nwhite);
  printf("others - %d\n", nother);
  return 0;
}

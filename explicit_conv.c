#include <stdio.h>

int main()
{
  int c, i=0;
  char ans[100];

  while((c=getchar())!='\n')
  {
    switch(c)
    {
      case '\t': ans[i]='\\'; i++; ans[i]='t'; i++; break;
      case ' ': ans[i]='*'; i++; ans[i]='s'; i++; ans[i]='p'; i++; ans[i]='*'; i++; break;
      default: ans[i]=c; i++; break;
    }
  }
  ans[i]='\\'; i++; ans[i]='n'; i++; ans[i]='\0';
  printf("%s", ans);
  return 0;
}

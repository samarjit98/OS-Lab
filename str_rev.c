#include <stdio.h>
#include <string.h>

void rev(char str[])
{
  int i, j; char tmp;
  for(i=0, j=strlen(str)-1; i<j; i++, j--)
  {
    tmp=str[i], str[i]=str[j], str[j]=tmp;
  }
}

int main()
{
  char str[100];
  gets(str);
  rev(str);
  printf("%s", str);
  return 0;
}

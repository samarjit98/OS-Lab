#include <stdio.h>
#include <stdlib.h>

int isDiv(long long n)
{
	int flag=0;
	for(long long i=1; i<=20; i++)
	{
		if(n%i!=0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)return 1;
	else return 0;
}

int main()
{
	for(long long i=2520;;i=i+10)
	{
		if(isDiv(i))
		{
			printf("%lli\n", i); break;
		}
	}
	return 0;
}

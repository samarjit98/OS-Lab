#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long n;
	scanf("%lli", &n);
	for(long long int i=2; i<=n; i++)
	{
		if(n%i==0)
		{
			printf("%lli\n", i);
			n /= i;
		}
	}
	return 0;
}

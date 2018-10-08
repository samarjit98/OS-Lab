#include <stdio.h>
#include <stdlib.h>

int isPalindrome(long long n)
{
	long long tmp=n, rev=0;
	while(tmp>0)
	{
		rev=10*rev+tmp%10;
		tmp/=10;
	}
	if(n==rev)return 1;
	else return 0;
}

int main()
{
	long long max=0, prod;
	for(long long i=999; i>=100; i--)
		for(long long j=999; j>=100; j--)
		{
			prod=i*j;
			if(prod>max && isPalindrome(prod))max=prod;
		}
	printf("%lli\n", max);
	return 0;
}

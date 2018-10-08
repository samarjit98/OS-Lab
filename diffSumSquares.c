#include <stdio.h>

int main()
{
	long long n=((100)*(201)*(101))/6;
	long long m=(100*101)/2;
  	printf("%lli\n", ((m*m-n)>0)?m*m-n:n-m*m);
	return 0;
}

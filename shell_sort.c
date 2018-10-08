#include <stdio.h>

void shellsort(int v[], int n)
{
  int gap, i, j, tmp;

  for(gap=n/2; gap>0; gap/=2)
    for(i=gap; i<n; i++)
      for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
      {
        tmp=v[j];
        v[j]=v[j+gap];
        v[j+gap]=tmp;
      }
}

int main()
{
  int arr[100], n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)scanf("%d", arr+i);
  shellsort(arr, n);
  for(int i=0; i<n; i++)printf("%d ", arr[i]);
  return 0;
}

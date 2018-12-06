#include <stdio.h>

int a[1004];

int main()
{
	int n, i, j, tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf(" %d", &a[i]);
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if( a[j-1] > a[j] )
			{
				tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}
	for(i=0;i<n;i++) printf("%d\n", a[i]);

	return 0;
}

#include <stdio.h>

int main()
{
	int n, k = 1;
	scanf("%d", &n);
	while(1)
	{
		scanf(" %d", &k);
		if(k==0) break;
		if(k%n==0)
		{
			printf("%d is a multiple of %d.\n", k, n);
		}
		else
		{
			printf("%d is NOT a multiple of %d.\n", k, n);
		}
	}
	return 0;
}
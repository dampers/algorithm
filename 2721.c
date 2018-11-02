#include <stdio.h>

int main()
{
	int i, t, n, j, sum;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		sum = 0;
		scanf("%d", &n);
		for(j=1;j<=n;j++)
		{
			sum += j*(j+1)*(j+2)/2;
		}
		printf("%d\n", sum);
	}
	return 0;
}

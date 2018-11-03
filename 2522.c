# include <stdio.h>
# include <math.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=1;i<=2*n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		}
		if(i>n) for(j=i;j>n;j--) printf(" ");
		if(i<=n)
		{
			for(j=0;j<i;j++)
			{
				printf("*");
			}
		}
		else
		{
			for(j=2*n-i;j>=1;j--)
			{
				printf("*");
			}
		}
		printf("\n");
		
	}
	return 0;
}

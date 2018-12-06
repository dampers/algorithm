# include <stdio.h>

int main()
{
	int n,j,i;
	for(n=2;n<10;n+=3)
	{
		for(j=1;j<=9;j++)
		{
			if(n<8)
			{
				for(i=n;i<n+3;i++)
				{
					printf("%d * %d = %2d    ",i,j,i*j);
				}
				printf("\n");

			}
			else
			{
				printf("%d * %d = %2d    ",n,j,n*j);
				printf("%d * %d = %2d\n",n+1,j,(n+1)*j);
			}
		}
		printf("\n");
	}
	return 0;
}


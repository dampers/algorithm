# include <stdio.h>

int main()
{
	int t, p, i, j, k, cnt;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		cnt = 0;
		scanf("%d", &p);
		printf("Pairs for %d: ", p);
		for(j=1;j<=p/2;j++)
		{
			for(k=2;k<=p;k++)
			{
				if(j+k == p && j != k)
				{
					if(cnt == 0)
					{
						printf("%d %d", j, k);
						cnt = 1;
					}
					else
					{
						printf(", %d %d", j, k);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}

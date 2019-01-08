# include <stdio.h>

int y[10000];

int main()
{
	int n, i, sum, cnt, j;
	while(1)
	{
		sum = 0;
		cnt = 0;
		scanf("%d", &n);
		if(n==-1) break;
		for(i=1;i<n;i++)
		{
			if(n%i==0)
			{
				sum += i;
				y[cnt] = i;
				cnt++;
				
			}
		}
		if(n==1) printf("1 = 1\n");
		else if(sum == n)
		{
			printf("%d = 1", n);
			for(j=1;j<cnt;j++)
			{
				printf(" + %d", y[j]);
			}
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", n);
        for(i=0;i<10000;i++) y[i]=0;
	}
	return 0;
}

# include <stdio.h>

int score[1005];

int main()
{
	int n,i,max = 0;
	double sum = 0.0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
		if (score[i] >= max) max = score[i];
	}
	for(i=0;i<n;i++)
	{
		sum += ((1.0*score[i])/(1.0*max)) * 100;
	}
	sum = sum/n;
	printf("%f",sum);
	
	return 0;
}

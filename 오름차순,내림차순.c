#include <stdio.h>
int main()
{
	int sum,i,j,max,b,min;
	sum=0;
	int p[8], index[5];
	for(i=0;i<8;i++)
	{
		scanf("%d",&p[i]);
	}
	for(j=0;j<5;j++)
	{
		max = 0;
		for(i=0;i<8;i++)
		{
			if(max <= p[i])
			{
				max = p[i];
				b = i;
			}
		}
		index[j] = b+1;
		p[b] = 0;
		sum += max;
	}	
	printf("%d\n",sum);
	for(j=0;j<5;j++)
	{
		min = 8;
		b=0;
		for(i=0;i<5;i++)
		{
			if(min >= index[i])
			{
				min = index[i];
				b = i;
			}
		}
		printf("%d ",min);
		index[b] = 8;
	}
	return 0;
}


# include <stdio.h>

int height[10];

int main()
{
	int i,j,k,sum=0,c,tmp;
	for(i=1;i<=9;i++)
	{
		scanf("%d",&height[i]);
		sum += height[i];
	}
	k = sum - 100;
	for(i=1;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			c = height[i] + height[j];	
			if(c == k)
			{
				height[i] = 0;
				height[j] = 0;
				break;
			}
		}
		if(c == k) break;
			
	}
	for(i=1;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			if(height[i]>=height[j])
			{
				tmp = height[i];
				height[i] = height[j];
				height[j] = tmp;
			}
		}
	}
	for(i=3;i<10;i++) printf("%d\n",height[i]);
	return 0;
}

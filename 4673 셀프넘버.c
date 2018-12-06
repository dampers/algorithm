#include <stdio.h>

int check[100000];

int main()
{
	int i,d,sum;
	for(i=1;i<=10000;i++)
	{
		d = i;
		sum = d;
		while(sum < 10001)
		{
			while(d>0)
			{
				sum += d%10;
				d = d/10;
			}
			check[sum] = 1;
			d = sum;
		}
	}
	for(i=1;i<=9993;i++)
	{
		if(check[i] == 0) printf("%d\n",i);
	}
	return 0;
}

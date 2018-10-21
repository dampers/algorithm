#include <stdio.h>
int main()
{
	int n,i,sum,c,p;
	p=0,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%1d",&c);
		if(c == 0)
		{
			p = 0;
		}
		else
		{
			p += 1;
		}
		sum += p;
	}
	printf("%d",sum);
	return 0;
}

#include <stdio.h>
int main()
{
	int s,p,t,i,j,g,pp;
	scanf("%d %d",&s,&p);
	t=p;
	for(i=1;i<=p;i++)
	{
		if(s%i==0 && p%i==0)
		{
			g = i;
		}	
	}
	pp = p/g;
	for(i=1;i<=p;i++)
	{
		if(i%pp == 0)
		{
			t--;
		}
	}
	printf("%d",t);
	return 0;	
}

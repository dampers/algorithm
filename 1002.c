# include <stdio.h>
# include <math.h>

int main()
{
	int x1,x2,y1,y2,r1,r2,t,i;
	double k,l;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		k = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
		l = sqrt(k);
		if(x1 == x2 && y1 == y2)
		{
			if(r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else
		{
			if(r1+r2 == l || abs(r1-r2) == l) printf("1\n");
			else if(abs(r1-r2) > l || r1+r2 < l) printf("0\n");
			else printf("2\n"); 
		}
	}
	return 0;
}

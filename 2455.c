#include <stdio.h>
int main(){
	int n;
	int t;
	int i;
	int s;
	int m;
	s=0;
	m=0;
	for(i=1;i<=4;i++)
	{
		scanf("%d %d",&n,&t);
		s = s-n+t;
		if (s>m)
		{
			m = s;
		}
	}
	printf("%d",m);
	return 0;
	}

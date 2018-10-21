#include <stdio.h>
int main(){
	int a;
	int b;
	int c;
	int d;
	scanf("%d %d\n%d",&a,&b,&c);
	a = a*60;
	d = a+b+c;
	a = d/60;
	b = d%60;
	if(a>=24)
	{
		a-=24;
	}
	printf("%d %d",a,b);
	return 0;
	}

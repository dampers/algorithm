#include <stdio.h>
int main(){
	int n,f,d;
	d = 0;
	scanf("%d\n%d",&n,&f);
	n = n/100*100;
	while( n%f != 0)
	{
		n += 1;
		d += 1;
	}
	if(d<10)
	{
		printf("0%d",d);
	}
	else
	{
		printf("%d",d);
	}
	return 0;
	}

#include <stdio.h>
int main()
{
	int a,b=0,i;
	for(i=0;i<5;i++)
	{
		scanf("%1d",&a);
		a *= a;
		b += a;
	}
	b = b%10;
	printf("%d",b);
	return 0;
}

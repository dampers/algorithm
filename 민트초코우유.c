#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n;
	int mint = 0, num = 0;
	scanf(" %d", &n);
	while(n>=1000 || num>=5)
	{
		while(n>=2000)
		{
			mint+=3;
			num+=3;
			n-=2000;
		}
		while(n>=1000)
		{
			mint++;
			num++;
			n-=1000;
		}
		while(num>=10)
		{
			mint+=3;
			num-=7; 
		}
		while(num>=5)
		{
			mint++;
			num-=4;
		}
	}
	printf("%d", mint);
	return 0;
}

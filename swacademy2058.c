#include<stdio.h>
#include<string.h>

int num[5];

int main()
{
	
	int n, tmp = 0, i;
	scanf("%d", &n);
	for(i=0;i<4;i++)
	{
		if(n>10)
		{
			tmp += n%10;
			n /= 10;
		}
		else tmp += n;
	}
	printf("%d", tmp);
	return 0;
}

# include <stdio.h>

int main()
{
	int n, p, cnt = 0;
	scanf("%d", &p);
	n = 1000-p;
	if(n>=500)
	{
		n -= 500;
		cnt++;
	}
	while(n>=100)
	{
		cnt++;
		n -= 100;
	}
	if(n>=50)
	{
		cnt++;
		n -= 50;
	}
	while(n>=10)
	{
		cnt++;
		n -= 10;
	}
	if(n>=5)
	{
		cnt++;
		n-=5;
	}
	printf("%d", cnt+n);
	return 0;
}

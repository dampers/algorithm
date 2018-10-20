#include <stdio.h>

int fib[41];

int main()
{
	int i, n, tmp;
	fib[0] = 0;
	fib[1] = 1;
	for(i=2;i<41;i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &tmp);
		if(tmp == 0) printf("%d %d\n", 1, 0);
		else if(tmp == 1) printf("%d %d\n", 0, 1);
		else printf("%d %d\n", fib[tmp-1], fib[tmp]);	
	}
	return 0;
}

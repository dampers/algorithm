#include <stdio.h>

int main()
{
	int n,i,cnt = 1;
	while(1)
	{
		scanf("%d", &n);
		if(n==0) break;
		if(n%2==0)
		{
			n = (3*(3*n)/2)/9;
			printf("%d. even %d\n", cnt, n);
		}
		else
		{
			n = ((3*n+1)/2*3)/9;
			printf("%d. odd %d\n", cnt, n);
		}
		cnt++;
	}
    return 0;
}

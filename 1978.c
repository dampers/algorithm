#include <stdio.h>

int main()
{
	int n, i, cnt = 0, s, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %d", &s);
		if(s == 1) continue;
		if(s == 2)
		{
			cnt++;
			continue;
		}
		else if(s%2 == 0) continue;
		for(j=3;(j*j)<=s;j++)
		{
			if(s%j == 0) break;
		}
		if(j*j>s) cnt++;
	}
	printf("%d", cnt);
	return 0;
}

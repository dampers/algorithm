#include <stdio.h>
int com[101];

int main()
{
	int n, i, cnt = 0, tmp;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %d", &tmp);
		if(com[tmp]) cnt++;
		else com[tmp] = 1;
	}
	printf("%d", cnt);
	return 0;
}

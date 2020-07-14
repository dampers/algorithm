#include <stdio.h>

int num[1001];

int main()
{
	int n;
	scanf(" %d", &n);

	while(n--)
	{
		int v;
		scanf(" %d", &v);
		for(int i=0;i<1001;i++) num[i] = 0;
		int k, mx = 0;
		for(int j=0;j<v;j++)
		{
			scanf(" %d", &k);
			num[k]++;
			if(num[mx]<num[k]) mx = k;
			else if(num[mx]==num[k] && mx>k) mx = k;
		}
		printf("%d\n", mx);
	}

	return 0;
}

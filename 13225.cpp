#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t, i, j, cnt;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		cnt = 0;
		scanf("%d", &n);
		for(j=1;j<=n;j++)
		{
			if(n%j==0)
			{
				cnt++;
			}
		}
		printf("%d %d\n", n, cnt);
	}
	return 0;
}

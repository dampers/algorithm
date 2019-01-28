#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int n, m, t;
	scanf(" %d", &t);
	for(int i=0;i<t;i++)
	{
		scanf(" %d %d", &n, &m);
		lld h, ans = n;
		if(n>=2) h = n-3;
		if(m == 0 || m == n)
			printf("1\n");
		else if(m == 1 || m == n-1)
			printf("%d\n", n);
		else
		{
			for(int j=2;j<=n/2;j++,h-=2)
			{
				ans += h;
				if(j == m)
				{
					break;
				}
				if(m>n/2 && n-j==m)
				{
					break;
				}
			}
			if(n%2==1 && m == n/2+1)
				printf("%lld\n", ans);
			else
				printf("%lld\n", ans);
		}
	}
	return 0;
}
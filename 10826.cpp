#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld f[10004];
int main()
{
	lld n;
	scanf("%lld", &n);
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	for(lld i=3;i<=n;i++)
	{
		f[i] = f[i-1]+f[i-2];
	}
	printf("%lld", f[n]);
	return 0;
}

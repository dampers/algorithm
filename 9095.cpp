#include <bits/stdc++.h>
#define swap(a,b) a^=b^=a^=b
using namespace std;
typedef long long lld;

lld dp[1000001];
int main()
{
	int t;
	scanf(" %d", &t);
	while(t--)
	{
		int n;
		scanf(" %d", &n);
		dp[n] = 1;
		for(int i=n;i>0;i--)
		{
			dp[i-1] += dp[i]%1000000009;
			if(i>1) dp[i-2] += dp[i]%1000000009;
			if(i>2) dp[i-3] += dp[i]%1000000009;
		}
		printf("%lld\n", dp[0]);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
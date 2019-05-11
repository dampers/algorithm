#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int n;
lld dp[100][2];
int main()
{
	scanf("%d", &n);
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	for(int i=4;i<=n;i++)
	{
		dp[i][0] = dp[i-1][0]+dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	printf("%lld\n", dp[n][0]*2+dp[n][1]);
	return 0;
}
#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld dp[55];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++)
	{
		dp[i] = dp[i-1]+dp[i-2]+1;
		dp[i] %= 1000000007;
	}
	cout<<dp[n];
	return 0;
}
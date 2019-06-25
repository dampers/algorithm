#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int dp[305];
int point[303];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>point[i];
	}
	dp[1] = point[1];
	dp[2] = point[1]+point[2];
	for(int i=3;i<=n;i++)
	{
		dp[i] = max(point[i-1]+point[i]+dp[i-3], dp[i-2]+point[i]);
	}
	cout<<dp[n];
	return 0;
}
#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int wine[10005], dp[10005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>wine[i];
	dp[1] = wine[1];
	dp[2] = wine[1]+wine[2];
	dp[3] = max(wine[1], wine[2])+wine[3];
	for(int i=4;i<=n;i++)
	{
		dp[i] = max(dp[i-3]+wine[i-1], dp[i-2])+wine[i];
		dp[i] = max(dp[i-4]+wine[i-1]+wine[i], dp[i]);
	}
	int mx = 0;
	for(int i=1;i<=n;i++)
	{
		cout<<dp[i]<<endl;
		mx = max(dp[i], mx);
	}
	cout<<mx;

	return 0;
}
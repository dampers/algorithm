#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<lld> dp(n+2, 0LL);
	vector<vector<pair<int, lld>>> v(n+2);
	for(int i=1;i<=n;i++)
	{
		int t, p;
		cin>>t>>p;
		if(i+t-1<=n) v[i+t].push_back({t, p});
	}
	lld mx = 0LL;
	for(int i=2;i<=n+1;i++)
	{
		dp[i] = mx;
		for(int j=0;j<v[i].size();j++)
		{
			dp[i] = max(dp[i], dp[i-v[i][j].first]+v[i][j].second);
		}
		mx = max(dp[i], mx);
	}
	cout<<mx;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int dp[20];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++)
	{
		int t, p;
		cin>>t>>p;
		v.push_back({t, p});
	}
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		if(i+v[i].first<=n)
		{
			dp[i+v[i].first] = max(dp[i+v[i].first], dp[i]+v[i].second);
			for(int j=i+v[i].first;j<=n;j++)
				dp[j] = max(dp[j], dp[i+v[i].first]);
		}
	}
	cout<<dp[n];
	return 0;
}
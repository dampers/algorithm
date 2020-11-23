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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<vector<int>> v(n, vector<int> (n+1, 0));
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>v[i][j];
		vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>> (n+1, {0, 0}));
		dp[0][0].first = 1;
		dp[0][0].second = v[0][0];
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(dp[i+1][j].second<dp[i][j].second+v[i+1][j])
				{
					dp[i+1][j].first = dp[i][j].first;
					dp[i+1][j].second = dp[i][j].second+v[i+1][j];
				}
				else if(dp[i+1][j].second==dp[i][j].second+v[i+1][j])
					dp[i+1][j].first+=dp[i][j].first;
				if(dp[i+1][j+1].second<dp[i][j].second+v[i+1][j+1])
				{
					dp[i+1][j+1].first = dp[i][j].first;
					dp[i+1][j+1].second = dp[i][j].second+v[i+1][j+1];
				}
				else if(dp[i+1][j+1].second==dp[i][j].second+v[i+1][j+1])
					dp[i+1][j+1].first+=dp[i][j].first;
			}
		}
		int mx = dp[n-1][0].second-1, cnt = 0;
		for(int i=0;i<n;i++)
		{
			if(mx<dp[n-1][i].second)
			{
				cnt = dp[n-1][i].first;
				mx = dp[n-1][i].second;
			}
			else if(mx==dp[n-1][i].second) cnt += dp[n-1][i].first;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
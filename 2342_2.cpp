#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
using nmp = map<pii, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


int getCost(int a, int b)
{
	if(a == 0) return 2;
	if(a == b) return 1;
	if(abs(a-b) == 2) return 4;
	return 3;
}

int dp[100001][5][5];

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 	
 	memset(dp, -1, sizeof(dp));
 	dp[0][0][0] = 0;
 	int dpnum = 0;
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(dp[dpnum][i][j] == -1) continue;
				int lcost = dp[dpnum][i][j] + getCost(i, n);
				int rcost = dp[dpnum][i][j] + getCost(j, n);
				
				if(dp[dpnum+1][n][j] == -1) dp[dpnum+1][n][j] = lcost;
				else dp[dpnum+1][n][j] = min(lcost, dp[dpnum+1][n][j]);

				if(dp[dpnum+1][i][n] == -1) dp[dpnum+1][i][n] = rcost;
				else dp[dpnum+1][i][n] = min(rcost, dp[dpnum+1][i][n]);
			}
		}
		dpnum++;
	}

	int ans = INT_MAX;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(dp[dpnum][i][j] == -1) continue;
			ans = min(dp[dpnum][i][j], ans);
		}
	}
	cout << ans;

	return 0;
}
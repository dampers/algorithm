#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int mx = (1<<15);
	vector<vector<int>> dp(mx, vector<int>(5, 0));
	for(int i=1;i*i<mx;i++)
	{
		dp[i*i][1] = 1;
		for(int j=i*i;j<mx;j++)
		{
			dp[j][2] += dp[j-i*i][1];
			dp[j][3] += dp[j-i*i][2];
			dp[j][4] += dp[j-i*i][3];
		}
	}
	int n;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << endl;
	}

	return 0;
}

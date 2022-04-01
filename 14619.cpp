#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int recur(int cnt, int curr, vector<int>& height, vector<vector<int>>& adj, 
	vector<vector<int>>& dp)
{
	if(cnt == 0) return height[curr];
	if(dp[curr][cnt] >= 0) return dp[curr][cnt];
	int &ret = dp[curr][cnt];
	ret = INT_MAX;
	for(int next : adj[curr])
	{
		ret = min(ret, recur(cnt-1, next, height, adj, dp));
	}
	return ret;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n, m;
	cin >> n >> m;
	vector<int> height(n+1, 0);
	for(int i=1;i<=n;i++)
		cin >> height[i];
	vector<vector<int>> adj(n+1, vector<int>());
	int x, y;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<vector<int>> dp(n+1, vector<int>(501, -1));
	int q, a, k;
	cin >> q;
	while(q--)
	{
		cin >> a >> k;
		int ans = recur(k, a, height, adj, dp);
		cout << (ans==INT_MAX?-1:ans) << endl;
	}

	return 0;
}

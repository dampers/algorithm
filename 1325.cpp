#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool check[10001];

int dfs(int curr, vector<vector<int>>& adj)
{
	check[curr] = true;
	int ret = 1;
	for(int next : adj[curr])
	{
		if(check[next]) continue;
		ret += dfs(next, adj);
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
	vector<vector<int>> adj(n+1, vector<int>());
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		adj[b].push_back(a);
	}
	vector<int> ans(n+1, 0);
	int mx = 0;
	for(int i=1;i<=n;i++)
	{
		memset(check, false, sizeof(check));
		ans[i] = dfs(i, adj);
		mx = max(ans[i], mx);
	}
	for(int i=1;i<=n;i++)
		if(mx == ans[i]) cout << i << ' ';

	return 0;
}

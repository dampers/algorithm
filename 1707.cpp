#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dfs(int curr, int c, vector<vector<int>>& adj, vector<int>& color)
{
	color[curr] = c;
	for(int next : adj[curr])
	{
		if(!color[next])
		{
			dfs(next, 3-c, adj, color);
		}
	}
}

void solve()
{
	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj(V+1, vector<int>());
	int a, b;
	for(int i=0;i<E;i++)
	{
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	vector<int> color(V+1, 0);
	for(int i=1;i<=V;i++)
	{
		if(!color[i]) dfs(i, 1, adj, color);
	}

	for(int i=1;i<=V;i++)
	{
		for(int K : adj[i])
		{
			if(color[i] == color[K])
			{
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}


int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	while(K-- > 0)
	{
		solve();
	}

	return 0;
}

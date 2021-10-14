#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<set<int>> adj(n+1, set<int>());
	vector<int> dist(n+1, 0);
	for(int i=0;i<n-1;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size() == 1)
		{
			q.push(i);
			dist[i] = 1;
		}
	}
	int cnt = 1;
	while(!q.empty())
	{
		cnt++;
		int size = q.size();
		while(size--)
		{
			int curr = q.front();
			q.pop();
			for(auto &K : adj[curr])
			{
				adj[K].erase(curr);
				if(adj[K].size() == 1)
				{
					q.push(K);
					dist[K] = cnt;
				}
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(dist[i] > k) ans++;
	cout << ans << endl;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int tc;
	cin >> tc;
	while(tc--) solve();

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int dist[101][10001];

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, pii>>> adj(n+1, vector<pair<int, pii>>());
	int u, v, c, d;
	for(int i=0;i<k;i++)
	{
		cin >> u >> v >> c >> d;
		adj[u].push_back({d, {c, v}});
	}

	// priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    queue<pair<int, pii>> pq;
	for(int i=0;i<101;i++)
		for(int j=0;j<10001;j++)
			dist[i][j] = INT_MAX;
	// duration, {cost, curr}
	pq.push({0, {0, 1}});

	while(!pq.empty())
	{
		int cdur = pq.front().first;
		int ccost = pq.front().second.first;
		int curr = pq.front().second.second;
		pq.pop();

		if(dist[curr][ccost] < cdur) continue;
		for(size_t i=0;i<adj[curr].size();i++)
		{
			int ndur = adj[curr][i].first + cdur;
			int ncost = adj[curr][i].second.first + ccost;
			int next = adj[curr][i].second.second;
			if(ncost <= m && dist[next][ncost] > ndur)
			{
				for(int j=ncost+1;j<m;j++)
				{
					if(dist[next][j] <= ndur) break;
					dist[next][j] = ndur;
				}
				dist[next][ncost] = ndur;
				if(next != n) pq.push({ndur, {ncost, next}});
			}
		}
	}
	int ans = INT_MAX;
	for(int i=0;i<=m;i++)
		ans = min(ans, dist[n][i]);
	if(ans == INT_MAX) cout << "Poor KCM\n";
	else cout << ans << endl;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc-- > 0)
	{
		solve();
	}

	return 0;
}
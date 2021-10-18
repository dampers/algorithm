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
	int n, d, c;
	cin >> n >> d >> c;
	vector<vector<pii>> adj(n+1, vector<pii>());
	int a, b, s;
	vector<int> cost(n+1, INT_MAX);
	for(int i=0;i<d;i++)
	{
		cin >> a >> b >> s;
		adj[b].push_back({s, a});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, c});
	cost[c] = 0;
	while(!pq.empty())
	{
		int curr = pq.top().second;
		int ccost = pq.top().first;
		pq.pop();
		if(cost[curr] < ccost) continue;
		for(auto &K : adj[curr])
		{
			int next = K.second;
			int ncost = K.first;
			if(cost[next] > ccost+ncost)
			{
				cost[next] = ccost + ncost;
				pq.push({cost[next], next});
			}
		}
	}
	int cnt = 0, acost = 0;
	for(int i=1;i<=n;i++)
	{
		if(cost[i] == INT_MAX) continue;
		cnt++;
		acost = max(cost[i], acost);
	}
	cout << cnt << ' ' << acost << endl;

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
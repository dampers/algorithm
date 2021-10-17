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
 
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n+1, vector<pii>());
	vector<pii> ans;
	int a, b, c;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	vector<int> cost(n+1, INT_MAX);
	cost[1] = 0;
	pq.push({0, {1, 1}});
	
	while(!pq.empty())
	{
		int curr = pq.top().second.second;
		int pre = pq.top().second.first;
		int ccost = pq.top().first;
		pq.pop();
		if(cost[curr] < ccost) continue;
		if(curr != pre) ans.push_back({pre, curr});

		for(size_t i=0;i<adj[curr].size();i++)
		{
			int next = adj[curr][i].first;
			int ncost = adj[curr][i].second;
			if(cost[next] > ccost+ncost)
			{
				cost[next] = ccost + ncost;
				pq.push({cost[next], {curr, next}});
			}
		}
	}
	cout << ans.size() << endl;
	for(auto &K : ans)
	{
		cout << K.first << ' ' << K.second << endl;
	}

	return 0;
}
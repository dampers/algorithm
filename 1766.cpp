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
	vector<vector<int>> adj(n+1, vector<int>());
	vector<int> indegree(n+1, 0);
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1;i<=n;i++)
		if(indegree[i] == 0) pq.push(i);
	while(!pq.empty())
	{
		int curr = pq.top();
		pq.pop();
		cout << curr << ' ';
		for(int next : adj[curr])
			if(--indegree[next] == 0) pq.push(next);
	}
	return 0;
}
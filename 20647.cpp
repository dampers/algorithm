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

	int n;
	cin >> n;
	vector<vector<int>> adj(n+1, vector<int>());
	int a, b;
	for(int i=0;i<n-1;i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> check(n+1, false);
	check[1] = true;
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		int nk = 0;
		for(int next : adj[curr])
		{
			if(check[next]) continue;
			nk++;
			cnt++;
			q.push(next);
			check[next] = true;
		}
		if(nk == 0) continue;
		int nkcnt = ceil(log2(nk+1));
		cnt += nkcnt;
	}
	cout << cnt;
	return 0;
}

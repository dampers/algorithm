#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<int> A, B;
vector<bool> check;

bool dfs(int a, vector<vector<int>>& adj)
{
	check[a] = true;
	for(int b : adj[a])
	{
		if(B[b] == 0 || (!check[B[b]] && dfs(B[b], adj)))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	A.resize(n+1, 0);
	B.resize(m+1, 0);
	check.resize(n+1, false);

	vector<vector<int>> adj(n+1, vector<int>());
	for(int i=1;i<=n;i++)
	{
		int s, ni;
		cin >> s;
		while(s-->0)
		{
			cin >> ni;
			adj[i].emplace_back(ni);
		}
	}

	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(A[i] == 0)
		{
			fill(check.begin(), check.end(), false);
			if(dfs(i, adj)) ans++;
		}
	}

	cout << ans;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool dfs(int a, vector<int>& A, vector<int>& B, vector<vector<int>>& adj, vector<bool>& check)
{
	check[a] = true;
	for(int b : adj[a])
	{
		if(B[b] == 0 || (!check[B[b]] && dfs(B[b], A, B, adj, check)))
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
	vector<int> A(n+1, 0), B(m+1, 0);
	vector<vector<int>> adj(n+1, vector<int>());
	int s, tmp;
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		for(int j=0;j<s;j++)
		{
			cin >> tmp;
			adj[i].push_back(tmp);
		}
	}

	int ans = 0;
	vector<bool> check(n+1, false);
	for(int i=1;i<=n;i++)
	{
		if(A[i] == 0)
		{
			fill(check.begin(), check.end(), false);
			if(dfs(i, A, B, adj, check)) ans++;
		}
	}
	cout << ans;

	return 0;
}

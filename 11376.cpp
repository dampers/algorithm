#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<vector<int>> adj;
bool check[2022];
int A[2022], B[2022];

bool dfs(int a)
{
	check[a] = true;
	for(int &b : adj[a])
	{
		if(B[b] == 0 || (!check[B[b]] && dfs(B[b])))
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
	adj.resize(n+n+1, vector<int>());

	int task, cnt;
	for(int i=1;i<=n;i++)
	{
		cin >> cnt;
		while(cnt-- > 0)
		{
			cin >> task;
			adj[i<<1].emplace_back(task);
			adj[(i<<1)-1].emplace_back(task);
		}
	}

	int ans = 0;
	n += n;
	for(int i=1;i<=n;i++)
	{
		if(!A[i])
		{
			memset(check, false, sizeof(check));
			if(dfs(i)) ans++;
		}
	}
	cout << ans;

	return 0;
}

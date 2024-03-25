#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool dfs(int a, vector<int>& A, vector<int>& B, vector<pii>& range, vector<bool>& check)
{
	check[a] = true;
	int left = range[a].first, right = range[a].second;
	for(;left <= right;left++)
	{
		int b = left;
		if(B[b] == 0 || (!check[B[b]] && dfs(B[b], A, B, range, check)))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> A(m+1, 0), B(n+1, 0);
	vector<pii> range(m+1);
	for(int i=1;i<=m;i++)
	{
		cin >> range[i].first >> range[i].second;
	}

	vector<bool> check(m+1, false);
	int ans = 0;

	for(int i=1;i<=m;i++)
	{
		if(A[i] == 0)
		{
			fill(check.begin(), check.end(), false);
			if(dfs(i, A, B, range, check)) ans++;
		}
	}
	cout << ans << endl;
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
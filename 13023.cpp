#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool dfs(int curr, int cnt, vector<vector<int>>& v, vector<bool>& check)
{
	if(cnt == 4) return true;
	bool ret = false;
	check[curr] = true;
	for(int &next : v[curr])
	{
		if(check[next]) continue;
		ret |= dfs(next, cnt+1, v, check);
	}
	check[curr] = false;
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>());
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=0;i<n;i++)
	{
		vector<bool> check(n, false);
		if(dfs(i, 0, v, check))
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}

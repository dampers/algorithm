#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int dfs(int y, int x, vector<string>& v, vector<vector<bool>>& check)
{
	check[y][x] = true;
	int ret = 1;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny >= v.size() || nx >= v[0].size() || ny < 0 || nx < 0) continue;
		if(check[ny][nx] || v[y][x] != v[ny][nx]) continue;
		ret += dfs(ny, nx, v, check);
	}
	return ret;
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int m, n;
	cin >> m >> n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	int a = 0, b = 0;

	vector<vector<bool>> check(n, vector<bool>(m, false));
	int tmp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j]) continue;
			tmp = dfs(i, j, v, check);
			if(v[i][j] == 'W') a += tmp * tmp;
			else b += tmp * tmp;
		}
	}
	cout << a << ' ' << b;
	return 0;
}

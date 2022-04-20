#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m;
int bfs(int y, int x, vector<vector<int>>& v)
{
	if(v[y][x]) return 0;
	vector<vector<bool>> check(n, vector<bool>(m, false));
	queue<pii> q;
	q.push({y, x});
	check[y][x] = true;

	int ret = 0;
	while(!q.empty())
	{
		ret++;
		int size = q.size();
		while(size--)
		{
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for(int i=0;i<8;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m || check[ny][nx])
					continue;
				if(v[ny][nx] == 1) return ret;
				check[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> v[i][j];

	int ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ans = max(bfs(i, j, v), ans);
	cout << ans;


	return 0;
}

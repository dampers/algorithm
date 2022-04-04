#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
	int w, h, o, f, sx, sy, ex, ey;
	cin >> h >> w >> o >> f >> sy >> sx >> ey >> ex;
	vector<vector<int>> v(h+1, vector<int>(w+1, 0));
	int kx, ky, height;
	for(int i=0;i<o;i++)
	{
		cin >> ky >> kx >> height;
		v[ky][kx] = height;
	}
	vector<vector<bool>> check(h+1, vector<bool>(w+1, false));
	queue<pair<int, pii>> q;
	q.push({f, {sy, sx}});
	check[sy][sx] = true;
	while(!q.empty())
	{
		int force, x, y;
		force = q.front().first;
		x = q.front().second.second;
		y = q.front().second.first;
		q.pop();
		if(y == ey && x == ex)
		{
			cout << "잘했어!!\n";
			return;
		}
		if(force == 0) continue;
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny <= 0 || nx <= 0 || ny > h || nx > w || check[ny][nx]) continue;
			if(force >= v[ny][nx]-v[y][x])
			{
				check[ny][nx] = true;
				q.push({force-1, {ny, nx}});
			}
		}
	}
	cout << "인성 문제있어??\n";
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

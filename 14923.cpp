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
	int hx, hy, ex, ey;
	cin >> hy >> hx >> ey >> ex;
	vector<vector<int>> v(n, vector<int>(m, 0));
	hx--;
	hy--;
	ex--;
	ey--;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>> dist(2, vector<vector<int>>(n, vector<int>(m, -1)));
	queue<pair<int, pii>> q;
	q.push({0, {hy, hx}});
	dist[0][hy][hx] = 0;
	int cnt = 0;
	bool flag = false;
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		while(size--)
		{
			int used = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if(used == 0 && v[ny][nx] == 1 && dist[1][ny][nx] == -1)
				{
					if(ny == ey && nx == ex)
					{
						cout << cnt << endl;
						flag = true;
						break;
					}
					dist[1][ny][nx] = cnt;
					q.push({1, {ny, nx}});
				}
				else if(v[ny][nx] == 0 && dist[used][ny][nx] == -1)
				{
					if(ny == ey && nx == ex)
					{
						cout << cnt << endl;
						flag = true;
						break;
					}
					dist[used][ny][nx] = cnt;
					q.push({used, {ny, nx}});
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(!flag) cout << -1;
	return 0;
}

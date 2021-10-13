#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void fillv(vector<vector<int>>& v, int cnt, int value)
{
	for(int i=0;i<cnt;i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		for(int y=y1;y<=y2;y++)
			for(int x=x1;x<=x2;x++)
				v[y][x] = value;
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	vector<vector<int>> v(501, vector<int>(501, 0));
	fillv(v, n, 1);
	cin >> m;
	fillv(v, m, -1);

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({0, {0, 0}});
	vector<vector<int>> dist(501, vector<int>(501, INT_MAX));
	while(!pq.empty())
	{
		int curr = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if(curr > dist[y][x]) continue;
		if(y == 500 && x == 500) break;
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny > 500 || nx > 500 || ny < 0 || nx < 0) continue;
			if(v[ny][nx] == -1) continue;
			int next = curr + v[ny][nx];
			if(next < dist[ny][nx])
			{
				dist[ny][nx] = next;
				pq.push({next, {ny, nx}});
			}
		}
	}
	cout << (dist[500][500]>=INT_MAX?-1:dist[500][500]);

	return 0;
}
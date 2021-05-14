#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;
typedef pair<int, int> pii;


const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int w, h;


int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;
	vector<string> v(h);
	for(int i=0;i<h;i++)
		cin >> v[i];
	vector<pii> razer(2, {-1, -1});
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(v[i][j] == 'C')
			{
				if(razer[0].first == -1) razer[0] = {i, j};
				else razer[1] = {i, j};
			}
		}
	}
	vector<vector<int>> tmp(5, vector<int>(5, 4));
	vector<vector<vector<int>>> dist(4, vector<vector<int>>(h, vector<int>(w, INT_MAX)));
	priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
	for(int i=0;i<4;i++)
	{
		int ny = razer[0].first + dy[i], nx = razer[0].second + dx[i];
		if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if(v[ny][nx] == '*') continue;
		pq.push({{0, i}, {ny, nx}});
		dist[i][ny][nx] = 0;
	}

	while(!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cur = pq.top().first.first;
		int dir = pq.top().first.second;
		pq.pop();

		if(cur > dist[dir][y][x]) continue;

		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if(v[ny][nx] == '*') continue;
			int next = cur + (dir==i?0:1);
			if(next < dist[i][ny][nx])
			{
				dist[i][ny][nx] = next;
				pq.push({{next, i}, {ny, nx}});
			}
		}
	}

	int mn = INT_MAX;
	for(int i=0;i<4;i++)
		mn = min(mn, dist[i][razer[1].first][razer[1].second]);
	cout << mn;
	return 0;
}
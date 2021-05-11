#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

string maze[55];
int cost[55][55];

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		fill(cost[i], cost[i]+n, INT_MAX);
		cin >> maze[i];
	}

	cost[0][0] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {0, 0}});

	while(!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int tmp_cost = pq.top().first;
		pq.pop();
		if(cost[y][x] < tmp_cost) continue;

		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny >= n || nx >= n || ny < 0 || nx < 0) continue;
			int next_cost = tmp_cost + (maze[ny][nx] == '1'?0:1);
			if(cost[ny][nx] > next_cost)
			{
				cost[ny][nx] = next_cost;
				pq.push({next_cost, {ny, nx}});
			}
		}
	}
	cout << cost[n-1][n-1];
	return 0;
}
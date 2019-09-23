#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[505][505];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dp[505][505];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int ii=0;ii<m;ii++)
			cin>>num[i][ii];
	queue<pair<int ,pair<int, int>> bfs;
	bfs.push({1,{0,0}});
	while(!bfs.empty())
	{
		int cnt = 0, y = bfs.front().second.first, x = bfs.front().second.second, name = bfs.front().first;
		bfs.pop();
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny>=n||ny<0||nx>=m||nx<0) continue;
			if(num[y][x]>num[ny][nx])
			{
				if(dp[ny][nx]<name+cnt)
				{
					dp[ny][nx] = name+cnt;
					cnt++;
				}
				else
					dp[ny][nx]++;
			}
		}
	}
	return 0;
}
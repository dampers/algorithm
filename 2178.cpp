#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char paper[101][101];
bool visit[101][101];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main()
{
	int n, m;
	scanf(" %d %d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf(" %c", &paper[i][j]);
		}
	}
	visit[1][1] = true;
	queue<pair<int, int>> bfs;
	bfs.push({1, 1});
	int cnt = 0;
	while(!bfs.empty())
	{
		cnt++;
		int size = bfs.size();
		while(size--)
		{
			int x = bfs.front().second, y = bfs.front().first;
			if(x==m&&y==n)
			{
				printf("%d\n", cnt);
				return 0;
			}
			bfs.pop();
			for(int i=0;i<4;i++)
			{
				int nx = x+dx[i], ny = y+dy[i];
				if(nx<1||nx>m||ny<1||ny>n||visit[ny][nx]||paper[ny][nx]=='0') continue;
				bfs.push({ny, nx});
				visit[ny][nx] = true;
			}
		}
	}
	return 0;
}
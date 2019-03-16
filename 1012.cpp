#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
bool paper[51][51];
bool visit[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(ny>=0 && nx >=0 && ny<51 && nx<51 && !visit[ny][nx] && paper[ny][nx])
		{
			visit[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

int main()
{
	int t;
	scanf(" %d", &t);
	for(int q=0;q<t;q++)
	{
		int wcnt = 0;
		int n, m, y, x;
		scanf("%d %d", &m, &n);
		int b;
		scanf(" %d", &b);
		for(int j=0;j<b;j++)
			{
				scanf("%d %d", &x, &y);
				paper[y][x] = true;
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!visit[i][j] && paper[i][j])
				{
					visit[i][j] = true;
					dfs(i, j);
					wcnt++;
				}
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				visit[i][j] = false;
				paper[i][j] = false;
			}
		printf("%d\n", wcnt);
	}
	return 0;
}

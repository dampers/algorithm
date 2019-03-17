#include<bits/stdc++.h>
using namespace std;
int paper[101][101];
bool visit[101][101];
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x, int m)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<n && !visit[ny][nx] && paper[ny][nx]>m)
		{
			visit[ny][nx] = true;
			dfs(ny, nx, m);
		}
	}
	
}

int main()
{
	scanf(" %d", &n);
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %d", &paper[i][j]);
			mx = mx<paper[i][j]?paper[i][j]:mx;
		}
	}
	int mcnt = 1, tcnt = 0;
	for(int q=1;q<mx;q++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visit[i][j] && paper[i][j]>q)
				{
					visit[i][j] = true;
					tcnt++;
					dfs(i, j, q);
				}
			}
		}
		mcnt = tcnt>mcnt?tcnt:mcnt;
		tcnt = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				visit[i][j] = false;
	}
	printf("%d", mcnt);
	return 0;
}

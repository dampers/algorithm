#include<bits/stdc++.h>

using namespace std;
int b;
bool paper[101][101];
bool visit[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(nx>=0 && ny >= 0 && nx<n && ny<m && !visit[ny][nx] && !paper[ny][nx])
		{
			visit[ny][nx] = true;
			b++;
			dfs(ny, nx);
		}
	}	
}
vector<int> bcnt;

int main()
{
	int k;
	scanf(" %d %d %d", &m, &n, &k);
	int x1, y1, x2, y2;
	for(int i=0;i<k;i++)
	{
		scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
		for(int q=y1;q<y2;q++)
		{
			for(int w=x1;w<x2;w++)
			{
				paper[q][w] = true;
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!visit[i][j] && !paper[i][j])
			{
				b++;
				visit[i][j] = true;
				dfs(i, j);
				bcnt.push_back(b);
				b = 0;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	sort(bcnt.begin(), bcnt.end());
	for(int i=0;i<bcnt.size();i++)
		printf("%d ", bcnt[i]);
	return 0;
}

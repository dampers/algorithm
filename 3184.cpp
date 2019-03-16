#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char paper[251][251];
bool visit[251][251];
int r, c;
int ocnt, vcnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int y, int x)
{
	if(paper[y][x]=='v')
		vcnt++;
	else if(paper[y][x]=='o')
		ocnt++;
	for(int i=0;i<4;i++)
	{
		int ax = x+dx[i], ay = y+dy[i];
		if(ax>=0 && ax<c && ay>=0 && ay<r && paper[ay][ax]!='#' && !visit[ay][ax])
		{
			visit[ay][ax] = true;
			dfs(ay, ax);
		}
	}
	return;
}


int main()
{
	scanf("%d %d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", paper[i]);
	int olife = 0, vlife = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(paper[i][j]!='#' && !visit[i][j])
			{
				visit[i][j] = true;
				dfs(i, j);
				if(ocnt>vcnt)
					olife += ocnt;
				else
					vlife += vcnt;
				ocnt = vcnt = 0;
			}
		}
	}
	printf("%d %d", olife, vlife);
	return 0;
}

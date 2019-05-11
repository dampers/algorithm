#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int paper[501][501];
bool visit[501][501];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, mx;
int main()
{
	int tmp = 0;
	scanf(" %d %d", &n, &m);
	int cnt = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %1d", &paper[i][j]);
	queue<pair<int, int>> bfs;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(paper[i][j]==1 && !visit[i][j])
			{
				cnt++;
				tmp = 1;
				visit[i][j] = true;
				bfs.push({i, j});
				while(!bfs.empty())
				{
					int size = bfs.size();
					int y = bfs.front().first;
					int x = bfs.front().second;
					//printf("size = %d y = %d x = %d\n", size, y, x);
					bfs.pop();
					while(size--)
					{
						for(int q=0;q<4;q++)
						{
							int nx = x+dx[q], ny = y+dy[q];
							if(nx<0||ny<0||nx>=m||ny>=n||visit[ny][nx]||paper[ny][nx]==0) continue;
							visit[ny][nx] = true;
							bfs.push({ny, nx});
							tmp++;
						}
					}
				}
			}
			mx = tmp>mx?tmp:mx;
		}
	}
	if(cnt)
		printf("%d\n%d", cnt, mx);
	else
		printf("0\n0");
	return 0;
}
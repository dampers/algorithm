#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int paper[21][21];
bool visit[21][21];
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

int main()
{
	int i, j, q, w;
	int mn = 4000;
	int n,m, ocnt = 0;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf(" %1d", &paper[i][j]);
			if(paper[i][j]) ocnt++;
		}
	queue<pair<int, int>> bfs;
	int cnt = 0;
	int ncnt = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!visit[i][j]&&paper[i][j]==0)
			{
				for(q=i+1;q<n;q++)
				{
					for(w=j+1;w<m;w++)
					{
						if(!visit[q][w]&&paper[q][w]==0)
						{
							bfs.push(make_pair(i, j));
							bfs.push(make_pair(q, w));
							visit[i][j]=true;
							visit[q][w] = true;
							while(!bfs.empty())
							{
								int size = bfs.size();
								cnt++;
								while(size--)
								{
									int x = bfs.front().second;
									int y = bfs.front().first;
									bfs.pop();
									for(int r=0;r<4;r++)
									{
										int nx = x+dx[r], ny = y+dy[r];
										if(nx<0||ny<0||nx>m||ny>n||visit[ny][nx]) continue;
										if(paper[ny][nx]==1) ncnt++;
										visit[ny][nx] = true;
										if(ncnt==ocnt) break;
										bfs.push(make_pair(ny, nx));
									}
									if(ncnt==ocnt) break;
								}
								if(ncnt==ocnt) break;
							}
							if(ncnt==ocnt)
							{
								if(mn>cnt) mn = cnt;
								for(int k=0;k<n;k++)
									for(int h=0;h<m;h++)
										visit[k][h] = false;
								int size = bfs.size();
								while(size--) bfs.pop();
								ncnt = 0;
								cnt = 0;
							}
						}
					}
				}
			}
		}
	}
	printf("%d", mn);
	return 0;
}

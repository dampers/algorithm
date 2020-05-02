#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int robot[105][105];
bool check[5][105][105];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n, m, ey, ex, ed;

bool echeck(int y, int x, int dir)
{
	if(ey==y && ex==x && ed==dir) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>robot[i][j];
		}
	}
	int sy, sx, sd;
	cin>>sy>>sx>>sd;
	int order = 0;
	cin>>ey>>ex>>ed;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{sd, 0}, {sy, sx}});
	check[sd-1][sy][sx] = true;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int y = q.front().second.first, x = q.front().second.second;
			int dir = q.front().first.first;
			int cnt = q.front().first.second;
			if(echeck(y, x, dir))
			{
				cout<<cnt;
				return 0;
			}
			q.pop();
			bool wall = false;
			for(int i=1;i<4;i++)
			{
				if(wall) break;
				int ny = y+i*dy[dir-1], nx = x+i*dx[dir-1];
				if(ny<=n && nx<=m && ny>0 && nx>0 && !check[dir-1][ny][nx])
				{
					if(robot[ny][nx]==1)
					{
						wall = true;
						break;
					}
					check[dir-1][ny][nx] = true;
					q.push({{dir, cnt+1}, {ny, nx}});
				}
			}
			if(dir==1 || dir==2)
			{
				if(!check[2][y][x])
				{
					check[2][y][x] = true;
					q.push({{3, cnt+1}, {y, x}});
				}
				if(!check[3][y][x])
				{
					check[3][y][x] = true;
					q.push({{4, cnt+1}, {y, x}});
				}
			}
			else if(dir==3||dir==4)
			{
				if(!check[0][y][x])
				{
					check[0][y][x] = true;
					q.push({{1, cnt+1}, {y, x}});
				}
				if(!check[1][y][x])
				{
					check[1][y][x] = true;
					q.push({{2, cnt+1}, {y, x}});
				}
			}
		}
	}
	return 0;
}
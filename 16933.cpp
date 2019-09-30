#include <bits/stdc++.h>
using namespace std;

char miro[1005][1005];
bool check[12][1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<n;i++)
			scanf(" %s", &miro[i]);
	queue<pair<pair<int, int>, pair<int, int> > > bfs;
	bfs.push({{0,0},{0,1}});
	check[0][0][0] = true;
	bool flag = false;
	bool daylight = true;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int z = bfs.front().second.first, y = bfs.front().first.first, x = bfs.front().first.second;
			int cnt = bfs.front().second.second;
			if(y==n-1 && x==m-1)
			{
				printf("%d", cnt);
				return 0;
			}
			bfs.pop();
			bool kflag = false;
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=n||ny<0||nx>=m||nx<0||(z==k && miro[ny][nx]=='1')) continue;
				if(miro[ny][nx]=='1' && z<k && !check[z+1][ny][nx])
				{
					if(daylight)
					{
						check[z+1][ny][nx] = true;
						bfs.push({{ny,nx}, {z+1, cnt+1}});	
					}
					else if(!kflag)
					{
						bfs.push({{y, x}, {z, cnt+1}});
						kflag = true;
					}
				}
				else if(miro[ny][nx]=='0' && !check[z][ny][nx])
				{
					check[z][ny][nx] = true;
					bfs.push({{ny,nx}, {z, cnt+1}});
				}
			}
		}
		daylight = !daylight;
	}
	printf("-1");
	return 0;
}
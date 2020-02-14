#include <bits/stdc++.h>
using namespace std;

char ot[101][101];
bool check[2][101][101];
int pnum[2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
	int tc;
	scanf("%d", &tc);
	queue<pair<pair<int, int>, pair<int, int>>> q;
	while(tc--)
	{
		memset(check, false, sizeof(check));
		memset(ot, '\0', sizeof(ot));
		while(!q.empty()) q.pop();
		pnum[0] = 10001;
		pnum[1] = 10001;
		int r, c, cnt = 0;
		scanf("%d %d", &r, &c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				scanf(" %c", &ot[i][j]);
				if(ot[i][j]=='$')
				{
					ot[i][j] = '.';
					q.push({{0, cnt}, {i, j}});
					check[cnt++][i][j] = true;
				}
			}
		}
		while(!q.empty())
		{
			int size = q.size();
			while(size--)
			{
				int y = q.front().second.first, x = q.front().second.second;
				int key = q.front().first.first, num = q.front().first.second;
				//printf("key = %d num = %d y = %d x = %d\n", key, num, y, x);
				q.pop();
				for(int i=0;i<4;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=r||nx>=c||ny<0||nx<0)
					{
						printf("ny = %d, nx = %d\n", ny, nx);
						pnum[num] = min(pnum[num], key);
						printf("pnum[%d] = %d\n", num, pnum[num]);
						continue;
					}
					else if(ot[ny][nx]=='*'||check[num][ny][nx]) continue;
					check[num][ny][nx] = true;
					if(ot[ny][nx]=='.') q.push({{key, num}, {ny, nx}});
					else if(ot[ny][nx]=='#')
					{
						q.push({{key+1, num}, {ny, nx}});
						ot[ny][nx] = '.';
					}
				}
			}
		}
		printf("%d\n", pnum[0]+pnum[1]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

char iw[1505][1505];
bool check[1505][1505];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int yx[2][2];
int main()
{
	int r, c, yxcnt = 0;
	queue<pair<int, int>> q, iq, nq, wq;
	scanf("%d %d", &r, &c);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf(" %c", &iw[i][j]);
			if(iw[i][j]=='L')
			{
				yx[yxcnt][0] = i;
				yx[yxcnt][1] = j;
				yxcnt++;
				iw[i][j] = '.';
			}
			if(iw[i][j]=='.') iq.push({i, j});
		}
	}

	bool flag = false;
	int cnt = 0;
	q.push({yx[0][0], yx[0][1]});
	check[yx[0][0]][yx[0][1]] = true;
	while(!flag)
	{
		while(!nq.empty())
		{
			q.push(nq.front());
			nq.pop();
		}
		while(!q.empty())
		{
			if(flag) break;
			int size = q.size();
			while(size--)
			{
				if(flag) break;
				int y = q.front().first, x = q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=r||nx>=c||ny<0||nx<0||check[ny][nx]) continue;
					else if(iw[ny][nx]=='X')
					{
						check[ny][nx] = true;
						nq.push({ny, nx});
						continue;
					}
					if(ny==yx[1][0] && nx==yx[1][1])
					{
						flag = true;
						break;
					}
					check[ny][nx] = true;
					q.push({ny, nx});
				}
			}
		}
		if(flag) break;
		cnt++;
		while(!iq.empty())
		{
			int iy = iq.front().first, ix = iq.front().second;
			iq.pop();
			for(int i=0;i<4;i++)
			{
				int iny = iy+dy[i], inx = ix+dx[i];
				if(iny>=r||inx>=c||iny<0||inx<0) continue;
				else if(iw[iny][inx]=='X')
				{
					iw[iny][inx] = '.';
					wq.push({iny, inx});
				}
			}
		}
		while(!wq.empty())
		{
			iq.push({wq.front().first, wq.front().second});
			wq.pop();
		}
	}
	printf("%d", cnt);
	return 0;
}
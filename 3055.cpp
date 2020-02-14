#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char rh[55][55];
bool check[55][55];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c, y = 0, x = 0, yy = 0, xx = 0;
	scanf("%d %d", &r, &c);
	queue<pair<char, pair<int, int>>> q;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf(" %c", &rh[i][j]);
			if(rh[i][j]=='S')
			{
				y = i;
				x = j;
				rh[i][j] = '.';
			}
			else if(rh[i][j]=='D')
			{
				yy = i;
				xx = j;
			}
			else if(rh[i][j]=='*') q.push({'*', {i, j}});
		}
	}
	q.push({'S', {y, x}});
	check[y][x] = true;
	bool flag = false;
	int cnt = 0;
	while(!q.empty())
	{
		if(flag) break;
		int size = q.size();
		while(size--)
		{
			if(flag) break;
			y = q.front().second.first;
			x = q.front().second.second;
			char stat = q.front().first;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=r||nx>=c||ny<0||nx<0) continue;
				if(stat=='*' && rh[ny][nx]=='.')
				{
					rh[ny][nx] = '*';
					q.push({'*', {ny, nx}});
				}
				else if(stat=='S')
				{
					if(rh[ny][nx]=='*' || check[ny][nx] || rh[ny][nx]=='X') continue;
					if(ny==yy && nx==xx)
					{
						flag = true;
						break;
					}
					q.push({'S', {ny, nx}});
					check[ny][nx] = true;
				}
			}
		}
		cnt++;
	}
	if(flag) printf("%d", cnt);
	else printf("KAKTUS");
	return 0;
}
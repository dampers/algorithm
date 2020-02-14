#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char rh[1001][1001];
bool check[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf("%d", &n);
	queue<pair<char, pair<int, int>>> q;
	while(n--)
	{
		memset(rh, '\0', sizeof(rh));
		memset(check, false, sizeof(check));
		while(!q.empty()) q.pop();
		int r, c, y = 0, x = 0;
		scanf("%d %d", &r, &c);
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				scanf(" %c", &rh[i][j]);
				if(rh[i][j]=='@')
				{
					y = i;
					x = j;
					rh[i][j] = '.';
				}
				else if(rh[i][j]=='*') q.push({'*', {i, j}});
			}
		}
		q.push({'@', {y, x}});
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
					if(stat=='*')
					{
						if(ny>=c||nx>=r||ny<0||nx<0||rh[ny][nx]!='.') continue;
						rh[ny][nx] = '*';
						q.push({'*', {ny, nx}});
					}
					else if(stat=='@')
					{
						if(ny>=c||nx>=r||ny<0||nx<0)
						{
							flag = true;
							break;
						}
						if(rh[ny][nx]=='*' || check[ny][nx] || rh[ny][nx]=='#') continue;
						q.push({'@', {ny, nx}});
						check[ny][nx] = true;
					}
				}
			}
			cnt++;
		}
		if(flag) printf("%d\n", cnt);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
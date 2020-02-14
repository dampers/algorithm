#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int check[1001][1001];
int table[1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int direction[4];

vector<pair<int, int> > v;
int cnt, n, m;

void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=n || nx>=m || ny<0 || nx<0 || check[ny][nx]>0) continue;
		check[ny][nx] = 2;
		cnt++;
		cnt %= 10;
		v.push_back(make_pair(ny, nx));
		dfs(ny, nx);
	}
}


int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %1d", &check[i][j]);
	int dir = 10;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j]==0)
			{
				v.clear();
				check[i][j] = 2;
				cnt = 1;
				v.push_back(make_pair(i,j));
				dfs(i, j);
				cnt %= 10;
				int size = v.size();
				for(int k=0;k<size;k++)
					table[v[k].first][v[k].second] = cnt+dir;
				dir += 10;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j]==1)
			{
				memset(direction, 0, sizeof(direction));
				int dpoint = 0;
				bool flag = false;
				table[i][j] = 1;
				for(int k=0;k<4;k++)
				{
					flag = false;
					int ny = i+dy[k], nx = j+dx[k];
					if(ny>=n || nx>=m || ny<0 || nx<0 || check[ny][nx]==1) continue;
					int dtmp = table[ny][nx]-(table[ny][nx]%10);
					for(int dp=0;dp<dpoint;dp++)
					{
						if(dtmp==direction[dp])
						{
							flag = true;
							break;
						}
					}
					if(!flag)
					{
						table[i][j] += table[ny][nx]%10;
						direction[dpoint++] = dtmp;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j]==2) printf("0");
			else printf("%d", table[i][j]%10);
		}
		printf("\n");
	}
	return 0;
}
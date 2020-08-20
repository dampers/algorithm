#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

string game[55];
bool check[55][55];
int r, c, n, m;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
bool flag;

void dfs(int y, int x, int pos)
{
	check[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=n || ny<0 || nx>=m || nx<0) continue;
		if(ny==r && nx==c && pos>2 && game[ny][nx]==game[r][c])
		{
			flag = true;
			return ;
		}
		if(check[ny][nx]) continue;
		if(game[ny][nx]==game[r][c]) dfs(ny, nx, pos+1);
	}
	check[y][x] = false;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>game[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			r = i;
			c = j;
			dfs(i, j, 0);
			if(flag)
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
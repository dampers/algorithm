#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int tt[505][505];
bool check[505][505];
int mx, n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int flag;
void dfs(int pos, int sum, int x, int y)
{
	if(pos==4)
	{
		mx = max(mx, sum);
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(nx>m || nx<0 || ny>n || ny<0 || check[ny][nx]) continue;
		if(i==0) flag++;
		if(flag==4)
		{
			flag--;
			continue;
		}
		check[ny][nx] = true;
		dfs(pos+1, sum+tt[ny][nx], nx, ny);
		check[ny][nx] = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>tt[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			check[i][j] = true;
			flag = 0;
			dfs(0, 0, j, i);
			check[i][j] = false;
			if(j+2<m)
			{
				int tmp = tt[i][j]+tt[i][j+1]+tt[i][j+2];
				if(i>0)
				{
					tmp += tt[i-1][j+1];
					mx = max(tmp, mx);
					tmp -= tt[i-1][j+1];
				}
				if(i<n-1)
				{
					tmp += tt[i+1][j+1];
					mx = max(tmp, mx);
					tmp -= tt[i+1][j+1];
				}
			}
			if(i+2<n)
			{
				int tmp = tt[i][j]+tt[i+1][j]+tt[i+2][j];
				if(j-1>=0)
				{
					tmp += tt[i+1][j-1];
					mx = max(tmp, mx);
					tmp -= tt[i+1][j-1];
				}
				if(j+1<=m-1)
				{
					tmp += tt[i+1][j+1];
					mx = max(tmp, mx);
					tmp -= tt[i+1][j+1];
				}
			}
		}
	cout<<mx;
	return 0;
}
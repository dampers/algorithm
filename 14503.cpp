#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int vac[55][55], n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int dd[4][4] = {{3, 2, 1, 0}, {0, 3, 2, 1}, {1, 0, 3, 2}, {2, 1, 0, 3}};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	int y, x, d, cnt = 0;
	cin>>y>>x>>d;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>vac[i][j];
	bool vacflag = true;
	while(1)
	{
		if(vacflag)
		{
			vac[y][x] = 2;
			cnt++;
			vacflag = false;
		}
		int dcnt = 0;
		bool flag = false;
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[dd[d][i]], nx = x+dx[dd[d][i]];
			if(ny>=n||nx>=m||ny<0||nx<0||vac[ny][nx]>0)
			{
				dcnt++;
				continue;
			}
			else
			{
				y = ny;
				x = nx;
				d = dd[d][i];
				flag = true;
				vacflag = true;
				break;
			}
		}
		if(flag) continue;
		else
		{
			y = y-dy[dd[d][3]];
			x = x-dx[dd[d][3]];
			if(vac[y][x]==1) break;
		}
	}
	cout<<cnt;
	return 0;
}
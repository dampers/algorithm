#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int ice[303][303];
bool visit[303][303];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;

void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(nx<0 || ny<0 || ny>=n || nx>=m || visit[ny][nx] || !ice[ny][nx]) continue;
		visit[ny][nx] = true;
		dfs(ny, nx);
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
			cin>>ice[i][j];
	
	for(int ic=0;ic<11;ic++)
	{
		int y, x;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ice[i][j])
				{
					if(!flag)
					{
						flag = true;
						visit[i][j] = true;
						dfs(i, j);
					}
					else if(flag && !visit[i][j])
					{
						cout<<ic;
						return 0;
					}
				}
			}
		}
		memset(visit, false, sizeof(visit));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int iflag = 0;
				for(int kk=0;kk<4;kk++)
				{
					int ny = i+dy[kk], nx = j+dx[kk];
					if(nx<0 || ny<0 || ny>=n || nx>=m || visit[ny][nx] || ice[ny][nx]) continue;
					iflag++;
				}
				if(iflag) ice[i][j]-= iflag;
			}
		}
	}
	cout<<0;
	return 0;
}
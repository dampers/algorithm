#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char xax[55][55];
bool visit[65][55][55];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

class coord
{
public:
	int y;
	int x;
	char um;
	coord(int ky, int kx, char kum)
	{y = ky; x = kx; um = kum;}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int cnt = 1;
	int xcnt = 0;
    int xxcnt = 0;
	int ey, ex;
	queue<coord> q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>xax[i][j];
			if(xax[i][j]=='X')
			{
				xcnt++;
				xax[i][j] = '\0'+cnt;
                xxcnt += cnt;
				cnt *= 2;
			}
			else if(xax[i][j]=='S')
			{
				coord tmp(i,j,0);
				q.push(tmp);
				visit[0][i][j] = true;
			}
			else if(xax[i][j]=='E')
			{
				ey = i;
				ex = j;
			}
		}
	}
	cnt = 0;
	while(!q.empty())
	{
		if(visit[xxcnt][ey][ex]==true)
		{
			cout<<cnt;
			return 0;
		}
		cnt++;
		int size = q.size();
		while(size--)
		{
			int ay = q.front().y;
			int ax = q.front().x;
			char aum = q.front().um;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = ay+dy[i], nx = ax+dx[i];
				char num = aum;
				if(ny<=0 || ny>m || nx<=0 || nx>n || visit[num][ny][nx] || xax[ny][nx]=='#') continue;
				if(xax[ny][nx]<32 && !(xax[ny][nx]&num)) num += xax[ny][nx];
				visit[num][ny][nx] = true;
				coord tmp(ny,nx,num);
				q.push(tmp);
			}
		}
	}
	return 0;
}
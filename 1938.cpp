#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char tr[55][55];
bool check[2][55][55];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n;

struct sk
{
	int y;
	int x;
	int dir; // low = 1, col = 0
};
sk s, res;

void find()
{
	bool bflag = false, eflag = false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(tr[i][j]=='B' && !bflag)
			{
				bflag = true;
				if(i+1<n&&tr[i+1][j]=='B')
				{
					s.y = i+1;
					s.x = j;
					s.dir = 0;
				}
				else if(j+1<n&&tr[i][j+1]=='B')
				{
					s.y = i;
					s.x = j+1;
					s.dir = 1;
				}
			}
			else if(tr[i][j]=='E' && !eflag)
			{
				eflag = true;
				if(i+1<n&&tr[i+1][j]=='E')
				{
					res.y = i+1;
					res.x = j;
					res.dir = 0;
				}
				else if(j+1<n&&tr[i][j+1]=='E')
				{
					res.y = i;
					res.x = j+1;
					res.dir = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf(" %s", &tr[i]);
	find();
	queue<sk> q;
	q.push(s);
	check[s.dir][s.y][s.x] = true;
	int cnt = 0;
	bool qflag = false;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			sk tmp = q.front();
			q.pop();
			int ky = tmp.y, kx = tmp.x;
			int kdir = tmp.dir;
			if(ky==res.y && kx==res.x && kdir==res.dir)
			{
				qflag = true;
				break;
			}
			for(int i=0;i<4;i++)
			{
				int ny = ky+dy[i], nx = kx+dx[i];
				int lny = ny, lnx = nx, rny = ny, rnx = nx;
				if(kdir)
				{
					lnx--;
					rnx++;
				}
				else
				{
					lny--;
					rny++;
				}
				if(ny>=n||nx>=n||lny>=n||lnx>=n||rny>=n||rnx>=n) continue;
				if(ny<0||nx<0||lny<0||lnx<0||rny<0||rnx<0) continue;
				if(check[kdir][ny][nx]) continue;
				if(tr[ny][nx]=='1'||tr[lny][lnx]=='1'||tr[rny][rnx]=='1') continue;
				check[kdir][ny][nx] = true;
				q.push({ny, nx, kdir});
			}
			if(!check[kdir==1?0:1][ky][kx])
			{
				bool checkflag = false;
				for(int i=ky-1;i<ky+2;i++)
				{
					if(checkflag) break;
					for(int j=kx-1;j<kx+2;j++)
					{
						if(i>=n||j>=n||i<0||j<0||tr[i][j]=='1')
						{
							checkflag = true;
							break;
						}
					}
				}
				if(!checkflag)
				{
					check[kdir==1?0:1][ky][kx] = true;
					q.push({ky, kx, kdir==1?0:1});
				}
			}
		}
		if(qflag) break;
		cnt++;
	}
	if(qflag) cout<<cnt;
	else cout<<0;
	return 0;
}
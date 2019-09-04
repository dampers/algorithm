#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int tomato[101][101][101];
bool check[101][101][101];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

class coord
{
public:
	int x;
	int y;
	int z;
	coord(int a, int b, int c){z = a;y = b;x = c;};
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, h, tcnt = 0;
	cin>>m>>n>>h;
	queue<coord> q;
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
			{
				cin>>tomato[i][j][k];
				if(tomato[i][j][k]==1) q.push(coord(i,j,k));
				if(tomato[i][j][k]!=-1) tcnt++;
			}
	int cnt = -1;
	while(!q.empty())
	{
		cnt++;
		int size = q.size();
		for(int t=0;t<size;t++)
		{
			int az = q.front().z, ay = q.front().y, ax = q.front().x;
			q.pop();
			for(int i=0;i<6;i++)
			{
				int nz = az+dz[i], ny = ay+dy[i], nx = ax+dx[i];
				if(nz>=h || nz<0 || ny>=n || ny<0 || nx>=m || nx<0) continue;
				if(!check[nz][ny][nx] && tomato[nz][ny][nx]==0)
				{
					check[nz][ny][nx] = true;
					q.push(coord(nz, ny, nx));
					tomato[nz][ny][nx] = 1;
				}
			}
		}
	}
	int ocnt = 0;
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				if(tomato[i][j][k]==1) ocnt++;
	//cout<<ocnt<<' '<<tcnt<<endl;
	if(ocnt==tcnt)
		cout<<cnt;
	else cout<<-1;
	return 0;
}
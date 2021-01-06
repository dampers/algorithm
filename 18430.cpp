#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int n, m;
int bm[6][6];
bool check[6][6];

int dy[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int dx[4][2] = {{-1, 0}, {-1, 0}, {0, 1}, {0, 1}};

int backtrack(int y, int x, int point)
{
	int ret = point;
	for(int i=y;i<n;i++)
	{
		for(int j=x;j<m;j++)
		{
			if(check[i][j]==true) continue;
			for(int d=0;d<4;d++)
			{
				int ny1 = i+dy[d][0], ny2 = i+dy[d][1];
				int nx1 = j+dx[d][0], nx2 = j+dx[d][1];
				if(ny1>=n || ny2>=n || ny1<0 || ny2<0) continue;
				if(nx1>=m || nx2>=m || nx1<0 || nx2<0) continue;
				if(check[ny1][nx1] || check[ny2][nx2]) continue;
				check[i][j] = check[ny1][nx1] = check[ny2][nx2] = true;
				ret = max(ret, point+backtrack(i, j, bm[i][j]*2+bm[ny1][nx1]+bm[ny2][nx2]));
				check[i][j] = check[ny1][nx1] = check[ny2][nx2] = false;
			}
		}
		x = 0;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>bm[i][j];
		}
	}
	cout<<backtrack(0, 0, 0);
	return 0;
}

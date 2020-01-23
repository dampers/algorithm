#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int island[55][55];
bool check[55][55];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int y, int x, int w, int h)
{
	for(int i=0;i<8;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=h || nx>=w || ny<0 || nx<0) continue;
		if(check[ny][nx] || island[ny][nx]==0) continue;
		check[ny][nx] = true;
		dfs(ny, nx, w, h);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int w = 1, h = 1;
	while(1)
	{
		cin>>w>>h;
		memset(check, false, sizeof(check));
		memset(island, 0, sizeof(island));
		if(w==0 && h==0) break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>island[i][j];
		int cnt = 0;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(island[i][j]==1&&check[i][j]==false)
				{
					cnt++;

					check[i][j] = true;
					dfs(i, j, w, h);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
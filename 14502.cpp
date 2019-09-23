#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int virus[9][9];
bool check[9][9];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<pair<int, int>> v;
queue<pair<int, int>> bfs;
int vsize, mx, wall;
int n, m;

void dfs_bfs(int pos, int yind, int xind)
{
	if(pos==3)
	{
		int cnt = vsize;
		for(int i=0;i<vsize;i++)
		{
			bfs.push({v[i].first, v[i].second});
			check[v[i].first][v[i].second] = true;
		}
		while(!bfs.empty())
		{
			int y = bfs.front().first, x = bfs.front().second;
			bfs.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny>=n||ny<0||nx>=m||nx<0||check[ny][nx]||virus[ny][nx]!=0) continue;
				check[ny][nx] = true;
				cnt++;
				bfs.push({ny,nx});
			}
		}
		if(mx<n*m-wall-cnt) mx = n*m-wall-cnt;
		memset(check, false, sizeof(check));
		return;
	}

	for(int i=yind;i<n;i++)
	{
		for(int ii=xind;ii<m;ii++)
		{
			if(!virus[i][ii])
			{
				virus[i][ii] = 1;
				dfs_bfs(pos+1, i, ii+1);
				virus[i][ii] = 0;
			}
		}
		xind = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	queue<pair<int, int>> bfs;
	for(int i=0;i<n;i++)
	{
		for(int ii=0;ii<m;ii++)
		{
			cin>>virus[i][ii];
			if(virus[i][ii] == 2) v.push_back({i,ii});
			else if(virus[i][ii]==1) wall++;
		}
	}
	wall += 3;
	vsize = v.size();
	dfs_bfs(0, 0, 0);
	printf("%d", mx);
	return 0;
}
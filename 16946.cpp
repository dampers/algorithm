#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int miro[1001][1001];
bool check[1001][1001];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > wall;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %1d", &miro[i][j]);
			if(miro[i][j]==1) wall.push_back({i,j});
		}
	}
	int size = wall.size();
	queue<pair<int, int> > bfs;
	for(int i=0;i<size;i++)
	{
		int y = wall[i].first, x = wall[i].second;
		int cnt = 1;
		check[y][x] = true;
		bfs.push({y,x});
		while(!bfs.empty())
		{
			int qsize = bfs.size();
			while(qsize--)
			{
				int ky = bfs.front().first, kx = bfs.front().second;
				bfs.pop();
				for(int ii=0;ii<4;ii++)
				{
					int ny = ky+dy[ii], nx = kx+dx[ii];
					if(ny>=n||ny<0||nx>=m||nx<0||check[ny][nx]||miro[ny][nx]>0) continue;
					cnt++;
					printf("ny = %d nx = %d\n", ny, nx);
					check[ny][nx] = true;
					bfs.push({ny,nx});
				}
			}
		}
		miro[y][x] = cnt;
		memset(check, false, sizeof(check));
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d", miro[i][j]%10);
		}
		printf("\n");
	}
	return 0;
}
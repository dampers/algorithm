#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int chi[55][55];
bool check[55][55];
bool hcheck[15];
vector<pair<int, int>> host;
vector<pair<int, int>> cho;
queue<pair<int, int>> bfs;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int mn = 2555;
int n, m, client, hostsize;

void dfs_bfs(int pos, int ind)
{
	if(pos==m)
	{
		int chosize = cho.size(), cnt = 0, ccnt = 0, tmp = 0;
		for(int q=0;q<chosize;q++)
		{
			bfs.push({cho[q].first, cho[q].second});
			//printf("y = %d x = %d\n", cho[q].first, cho[q].second);
		}
		while(!bfs.empty())
		{
			int size = bfs.size();
			while(size--)
			{
				int y = bfs.front().first, x = bfs.front().second;
				bfs.pop();
				if(chi[y][x]==1)
				{
					ccnt++;
					cnt += tmp;
					if(ccnt==client) break;
				}
				for(int i=0;i<4;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=n||ny<0||nx>=n||nx<0||check[ny][nx]) continue;
					check[ny][nx] = true;
					bfs.push({ny,nx});
				}
			}
			tmp++;
		}
		int size = bfs.size();
		while(size--) bfs.pop();
		memset(check, false, sizeof(check));
		if(mn>cnt) mn = cnt;
		//printf("cnt = %d\n\n", cnt);
		return;
	}
	for(int i=ind;i<hostsize;i++)
	{
		if(!hcheck[i])
		{
			hcheck[i] = true;
			cho.push_back({host[i].first, host[i].second});
			dfs_bfs(pos+1, i+1);
			hcheck[i] = false;
			cho.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int ii=0;ii<n;ii++)
		{
			cin>>chi[i][ii];
			if(chi[i][ii]==1) client++;
			else if(chi[i][ii]==2) host.push_back({i,ii});
		}
	}
	hostsize = host.size();
	dfs_bfs(0, 0);
	cout<<mn;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
int w, h;
int d[59][59];
bool visit[59][59];
queue <pair<int, int>> bfs;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>w>>h;
	while(w!=0&&h!=0)
	{
		lld cnt=0;
		memset(visit, false, sizeof(visit));
		for(int i = 0; i<h; i++)
			for(int j = 0; j<w; j++)
				cin>>d[i][j];
		for(int i = 0; i<h; i++)
			for(int j = 0; j<w; j++)
			{
				if(d[i][j]==0||visit[i][j]) continue;
				bfs.push(make_pair(i, j));
				visit[i][j]=true;
				while(!bfs.empty())
				{
					int size = bfs.size();
					while(size--)
					{
						int x = bfs.front().first;
						int y = bfs.front().second;
						bfs.pop();
						for(int k = 0; k<8; k++)
						{
							int nx = x+dx[k];
							int ny = y+dy[k];
							if(nx<0||ny<0||nx>=h||ny>=w||visit[nx][ny]||d[nx][ny]==0) continue;
							visit[nx][ny] = true;
							bfs.push(make_pair(nx, ny));
						}
					}
				}
				cnt++;
			}
			cout<<cnt<<"\n";
		cin>>w>>h;
	}
	return 0;
}
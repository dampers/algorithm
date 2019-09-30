#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[303][303];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	queue<pair<int, int> > bfs;
	while(tc--)
	{
		int n;
		cin>>n;
		int sy, sx, ey, ex;
		cin>>sy>>sx>>ey>>ex;
		bfs.push({sy,sx});
		check[sy][sx]=true;
		int cnt = 0;
		bool flag = false;
		int size = bfs.size();
		while(!bfs.empty())
		{
			size = bfs.size();
			if(flag) break;
			while(size--)
			{
				int y = bfs.front().first, x = bfs.front().second;
				bfs.pop();
				if(y==ey&&x==ex)
				{
					flag = true;
					break;
				}
				for(int i=0;i<8;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=n||ny<0||nx>=n||nx<0||check[ny][nx]) continue;
					check[ny][nx] = true;
					bfs.push({ny,nx});
				}
			}
			cnt++;
		}
		while(size--) bfs.pop();
		memset(check, false, sizeof(check));
		printf("%d\n", cnt-1);
	}
	return 0;
}
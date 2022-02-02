#include<bits/stdc++.h>
using namespace std;

int n,m,k;
bool dist[1001][1001][11];

struct point
{
	int x;
	int y;
	int cc;
};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(vector<string>& arr)
{
	queue<point> q;
	q.push({0,0,0});
	dist[0][0][0]=true;
	int cnt = 0;
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		while(size--)
		{
			int x=q.front().x, y=q.front().y, cc=q.front().cc;
			q.pop();
			if(y==n-1&&x==m-1)
			{
				return cnt;
			}
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(ny == n-1 && nx == m-1)
				{
					return cnt+1;
				}
				if(nx>=0 && ny>=0 && nx<m && ny<n)
				{
					if(dist[ny][nx][cc]==false && arr[ny][nx]=='0')
					{
						dist[ny][nx][cc]=true;
						q.push({nx,ny,cc});
					}
					else if(cc < k && dist[ny][nx][cc+1]==false && arr[ny][nx]=='1')
					{
						dist[ny][nx][cc+1]=true;
						q.push({nx,ny,cc+1});
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	vector<string> arr(n, "");
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << bfs(arr);
	return 0;
}

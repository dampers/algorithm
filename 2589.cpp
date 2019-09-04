#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char island[55][55];
bool check[55][55];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, mx = 0;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		scanf(" %s", island[i]);
	queue<pair<int, int> > q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(island[i][j]=='L')
			{
				memset(check, false, sizeof(check));
				check[i][j] = true;
				q.push({i, j});
				int cnt = -1;
				while(!q.empty())
				{
					cnt++;
					int size = q.size();
					for(int k=0;k<size;k++)
					{
						int y = q.front().first, x = q.front().second;
						q.pop();
						for(int l=0;l<4;l++)
						{
							int ny = y+dy[l], nx = x+dx[l];
							if(ny>=n || nx>=m || ny<0 || nx<0) continue;
							if(island[ny][nx]=='L' && !check[ny][nx])
							{
								check[ny][nx] = true;
								q.push({ny, nx});
							}
						}
					}
				}
				mx = max(mx, cnt);
			}
		}
	}
	printf("%d", mx);
	return 0;
}
#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int chz[101][101], s[101][101];
bool check[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cnt = 0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>chz[i][j];
			if(chz[i][j]==1)
			{
				cnt++;
			}
		}
	}
	queue<pair<int, int>> q, cz;
	int hour = 0;
	while(cnt>0)
	{
		memset(check, false, sizeof(check));
		memset(s, 0, sizeof(s));
		q.push({0, 0});
		while(!q.empty())
		{
			int size = q.size();
			while(size--)
			{
				int y = q.front().first, x = q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=n || nx>=m || ny<0 || nx<0 || check[ny][nx]) continue;
					if(chz[ny][nx]==1)
					{
						s[ny][nx] += 1;
						if(s[ny][nx]==2) cz.push({ny, nx});
					}
					else
					{
						check[ny][nx] = true;
						q.push({ny, nx});
					}
				}
			}
		}
		hour++;
		while(!cz.empty())
		{
			int ky = cz.front().first, kx = cz.front().second;
			cz.pop();
			chz[ky][kx] = 0;
			cnt--;
		}
	}
	cout<<hour;
	return 0;
}
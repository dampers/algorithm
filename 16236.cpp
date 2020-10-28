#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool check[22][22];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	pair<int, int> shark;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
			if(v[i][j]==9)
			{
				shark.first = i;
				shark.second = j;
				v[i][j] = 0;
			}
		}
	}
	int ssize = 2, ans = 0, fcnt = 0;
	while(1)
	{
		memset(check, false, sizeof(check));
		bool flag = false;
		queue<pair<int, int>> q;
		q.push(shark);
		check[shark.first][shark.second] = true;
		int fy = -1, fx = -1, mn = (int)1e9;
		int cnt = 0;
		while(!q.empty())
		{
			cnt++;
			if(flag) break;
			int size = q.size();
			while(size--)
			{
				int y = q.front().first, x = q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int ny = y+dy[i], nx = x+dx[i];
					if(ny>=n || nx>=n || ny<0 || nx<0) continue;
					if(check[ny][nx] || v[ny][nx]>ssize) continue;
					check[ny][nx] = true;
					q.push({ny, nx});
					if(v[ny][nx]<ssize && v[ny][nx]>0)
					{
						flag = true;
						if(mn>cnt)
						{
							mn = cnt;
							fy = ny;
							fx = nx;
						}
						else if(mn==cnt)
						{
							if(fy>ny)
							{
								fy = ny;
								fx = nx;
							}
							else if(fy==ny && fx>nx)
							{
								fy = ny;
								fx = nx;
							}
						}
					}
				}
			}	
		}
		if(!flag) break;
		v[fy][fx] = 0;
		ans += mn;
		fcnt++;
		if(fcnt==ssize)
		{
			fcnt = 0;
			ssize++;
		}
		shark.first = fy;
		shark.second = fx;
	}
	cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int parent[55][55];
int n;

void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			parent[i][j] = i*n+j;
}

int find(int y, int x)
{
	int k = y*n+x;
	if(parent[y][x]==k) return k;
	else return parent[y][x] = find(parent[y][x]/n, parent[y][x]%n);
}

bool merge(int y1, int x1, int y2, int x2)
{
	int u = find(y1, x1), v = find(y2, x2);
	if(u==v) return false;
	if(u>v)
	{
		y1 = u/n;
		x1 = u%n;
		parent[y1][x1] = v;
	}
	else
	{
		y2 = v/n;
		x2 = v%n;
		parent[y2][x2] = u;
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, r;
	cin>>n>>l>>r;
	vector<vector<int>> mp(n, vector<int> (n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mp[i][j];
	int cnt = 0;
	while(1)
	{
		bool flag = true;
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<4;k++)
				{
					int ny = i+dy[k], nx = j+dx[k];
					if(ny>=n||nx>=n||ny<0||nx<0) continue;
					int sub = abs(mp[ny][nx]-mp[i][j]);
					if(sub>=l && sub<=r) flag = merge(i, j, ny, nx);
				}
			}
		}
		if(flag) break;
		vector<pair<int, int>> v(n*n, {0, 0});
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int pk = find(i, j);
				v[pk].first++;
				v[pk].second += mp[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int pk = find(i, j);
				mp[i][j] = v[pk].second/v[pk].first;
			}
		}		
		cnt++;
	}
	cout<<cnt;
	return 0;
}
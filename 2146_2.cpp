#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int check[101][101];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n;

void dfs(vector<vector<int>>& mp, int cnt, int y, int x, vector<vector<pair<int, int>>>& v)
{
	check[y][x] = 1;
	mp[y][x] = cnt;
	bool flag = false;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
		if(check[ny][nx]) continue;
		if(mp[ny][nx] == 1) dfs(mp, cnt, ny, nx, v);
		else if(!flag)
		{
			flag = true;
			v[cnt-1].push_back({y, x});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	vector<vector<int>> mp(n, vector<int> (n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mp[i][j];
	int cnt = 1;
	vector<vector<pair<int, int>>> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]==1 && !check[i][j])
			{
				v.push_back(vector<pair<int, int>> ());
				dfs(mp, cnt, i, j, v);
				cnt++;
			}
		}
	}

	int mn = INT_MAX;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=i+1;k<v.size();k++)
			{
				for(int kk=0;kk<v[k].size();kk++)
				{
					int dist = abs(v[i][j].first-v[k][kk].first);
					dist += abs(v[i][j].second-v[k][kk].second);
					mn = min(mn, dist);
				}
			}
		}
	}
	cout<<mn-1;
	return 0;
}

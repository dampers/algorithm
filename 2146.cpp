#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int check[101][101];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n;

void dfs(vector<vector<int>>& mp, int cnt, int y, int x, queue<pair<int, pair<int, int>>>& q)
{
	check[y][x] = 1;
	mp[y][x] = cnt;
	bool flag = false;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
		if(check[ny][nx]) continue;
		if(mp[ny][nx] == 1) dfs(mp, cnt, ny, nx, q);
		else if(!flag)
		{
			flag = true;
			q.push({cnt, {y, x}});
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
	queue<pair<int, pair<int, int>>> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]==1 && !check[i][j])
			{
				dfs(mp, cnt, i, j, q);
				cnt++;
			}
		}
	}
	memset(check, 0, sizeof(check));
	int ans = 0, flag = 0;
	while(!q.empty())
	{
		int size = q.size();
		ans++;
		while(size--)
		{
			int num = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
				if(mp[ny][nx]==0)
				{
					mp[ny][nx] = num;
					check[ny][nx] = ans;
					q.push({num, {ny, nx}});
				}
				else if(mp[ny][nx]!=num)
				{
					flag = 2;
					if(check[ny][nx]==ans) flag = 1; 
					break;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	cout<<ans*2-flag;
	return 0;
}

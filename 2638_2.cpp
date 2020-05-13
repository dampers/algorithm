#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int n, m;
int chz[101][101], s[101][101];
bool check[101][101];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void dfs(int y, int x)
{
	check[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>=n || nx>=m || ny<0 || nx<0 || check[ny][nx]) continue;
		if(chz[ny][nx]==1)
		{
			s[ny][nx]++;
			if(s[ny][nx]==2) q.push({ny, nx});
		}
		else dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>chz[i][j];
			if(chz[i][j]) cnt++;
		}
	}
	int hour = 0;
	while(cnt>0)
	{
		memset(check, false, sizeof(check));
		memset(s, 0, sizeof(s));
		dfs(0, 0);
		hour++;
		while(!q.empty())
		{
			int y = q.front().first, x = q.front().second;
			q.pop();
			chz[y][x] = 0;
			cnt--;
		}
	}
	cout<<hour;
	return 0;
}
#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int bd[6][6];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
map<int, int> mp;
int cnt;
void dfs(int pos, int ans, int y, int x)
{
	if(pos==5)
	{
		if(mp[ans]>0) return;
		cnt++;
		mp[ans] = 1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny>4 || nx>4 || ny<0 || nx<0) continue;
		dfs(pos+1, ans*10+bd[ny][nx], ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>bd[i][j];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			dfs(0, bd[i][j], i, j);
		}
	}
	cout<<cnt;
	return 0;
}
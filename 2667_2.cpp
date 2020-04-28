#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int n;
int apartment[26][26];
bool check[26][26];
int cnt, dcnt;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1 ,1};

void dfs(int y, int x)
{
	cnt++;
	check[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<n && nx<n && ny>=0 && nx>=0 && check[ny][nx]==false && apartment[ny][nx]==1)
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %1d", &apartment[i][j]);
		}
	}
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(check[i][j]==false && apartment[i][j]==1)
			{
				dcnt++;
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", dcnt);
	for(int i=0;i<v.size();i++)
		printf("%d\n", v[i]);
	return 0;
}
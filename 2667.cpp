#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char paper[26][26];
bool visit[26][26];
vector<int> dcnt;
int cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if(ny>=0 && nx >=0 && ny<26 && nx< 26 && paper[ny][nx]=='1' && !visit[ny][nx])
		{
			visit[ny][nx] = true;
			cnt++;
			dfs(ny, nx);
		}
	}
}

int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", paper[i]);
	int dan = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(paper[i][j]=='1' && !visit[i][j])
			{
				visit[i][j] = true;
				cnt++;
				dfs(i, j);
				dcnt.push_back(cnt);
				cnt = 0;
				dan++;
			}
		}
	}
	sort(dcnt.begin(), dcnt.end());
	printf("%d\n", dan);
	for(int i=0;i<dcnt.size();i++)
	{
		printf("%d\n", dcnt[i]);
	}
	return 0;
}

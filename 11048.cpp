#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int miro[1002][1002];
int dp[1002][1002];
int dx[] = {1, 0};
int dy[] = {0, 1};
int main()
{
	clock_t start, end;
start = clock();
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>miro[i][j];
	dp[0][0] = miro[0][0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = j, y = i;
			for(int i=0;i<2;i++)
			{
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx<0 || nx>m-1 || ny<0 || ny>n-1) continue;
				dp[ny][nx] = max(dp[y][x]+miro[ny][nx], dp[ny][nx]);
			}
		}
	}
	printf("%d", dp[n-1][m-1]);
	end = clock();
double time = (double)(end-start)/CLOCKS_PER_SEC;
	//cout<<"finished at: "<< time;
	return 0;
}
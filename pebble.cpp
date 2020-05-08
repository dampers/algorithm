#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int peb[4][33];
int dp[4][33];

int pebble(int n)
{
	for(int p=0;p<4;p++)
	{
		dp[p][0] = peb[p][0];
	}
	for(int i=1;i<n;i++)
	{
		for(int p=0;p<4;p++)
		{
			if(p==0)
				dp[p][i] = max(dp[1][i-1], dp[2][i-1])+peb[p][i];
			else if(p==1)
				dp[p][i] = max(dp[0][i-1], max(dp[2][i-1], dp[3][i-1]))+peb[p][i];
			else if(p==2)
				dp[p][i] = max(dp[0][i-1], dp[2][i-1])+peb[p][i];
			else
				dp[p][i] = dp[1][i-1]+peb[p][i];
		}
	}
	int res = dp[0][n-1];
	for(int i=1;i<4;i++)
		res = max(res, dp[i][n-1]);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	printf("Input Table (3*8)\n\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			scanf("%d", &peb[i][j]);
		}
	}
	printf("W Table\n");
	for(int i=0;i<8;i++)
	{
		peb[3][i] = peb[0][i]+peb[2][i];
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
			printf("%3d ", peb[i][j]);
		printf("\n");
	}
	int sol = pebble(8);
	printf("\nDP Table\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
			printf("%3d ", dp[i][j]);
		printf("\n");
	}
	printf("\nOptimal solution : %d\n", pebble(8));
	return 0;
}
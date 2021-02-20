#include <bits/stdc++.h>
using namespace std;
 
long long dp[101][101];
long long init[101][101];
int n;
long long top_down(int y, int x)
{
	if(dp[y][x] != -1) return dp[y][x];
	if(y == n-1 && x == n-1) return 1;
	dp[y][x] = 0;
	long long ret = 0;
	if(init[y][x] + y < n) ret += top_down(y+init[y][x], x);
	if(init[y][x] + x < n) ret += top_down(y, x+init[y][x]);
	dp[y][x] = ret;
	//cout << y << ' ' << x << ' ' << dp[y][x] << endl;
	return dp[y][x];
}
 
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> init[i][j];
			dp[i][j] = -1;
		}
	}
	cout << top_down(0, 0);
	return 0;
}
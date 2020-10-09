#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n;

int jump(int y, int x, vector<vector<int>>& v, vector<vector<int>>& dp)
{
	if(y>=n||x>=n) return 0;
	if(y==n-1 && x==n-1) return 1;
	if(dp[y][x]!= -1) return dp[y][x];
	return dp[y][x] = jump(y+v[y][x], x, v, dp)+jump(y, x+v[y][x], v, dp);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		vector<vector<int>> v(n, vector<int>(n)), dp(n, vector<int>(n, -1));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		if(jump(0, 0, v, dp)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
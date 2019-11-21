#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int a[200005], b[200005], dp[200005][4];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c;
	cin>>n>>c;
	for(int i=1;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		cin>>b[i];
	dp[1][1] = a[1];
	dp[1][2] = b[1]+c;
	dp[1][0] = min(dp[1][1], dp[1][2]);
	cout<<0<<' '<<dp[1][0]<<' ';
	for(int i=2;i<n;i++)
	{
		dp[i][1] = min(dp[i-1][1], dp[i-1][2])+a[i];
		dp[i][2] = min(dp[i-1][1]+c+b[i], dp[i-1][2]+b[i]);
		dp[i][0] = min(dp[i][1], dp[i][2]);
		//cout<<dp[i][1]<<' '<<dp[i][2]<<' ';
		cout<<dp[i][0]<<' ';
	}
	return 0;
}
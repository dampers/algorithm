#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int dp[10005], wine[10005];


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>wine[i];
	dp[0] = wine[0];
	dp[1] = wine[0]+wine[1];
	dp[2] = max(wine[0], wine[1])+wine[2];
	dp[2] = max(dp[2], dp[1]);
	int mx = dp[2];
	for(int i=3;i<n;i++)
	{
		dp[i] = max(dp[i-2], dp[i-3]+wine[i-1])+wine[i];
		if(i>3)dp[i] = max(dp[i], wine[i-1]+wine[i-2]+dp[i-4]);
		mx = max(dp[i], mx);
	}
	cout<<mx<<endl;
	return 0;
}
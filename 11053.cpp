#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[1005], dp[1005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<n;i++)
	{
		if(dp[i]==0) dp[i] = 1;
		for(int ii=0;ii<i;ii++)
		{
			if(num[i]>num[ii]) dp[i] = max(dp[i], dp[ii]+1);
		}
	}
	int mx = 0;
	for(int i=0;i<n;i++)
		mx = max(mx, dp[i]);
	cout<<mx;
	return 0;
}